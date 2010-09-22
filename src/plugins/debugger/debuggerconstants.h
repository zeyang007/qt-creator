/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#ifndef DEBUGGERCONSTANTS_H
#define DEBUGGERCONSTANTS_H

#include <QtCore/QtGlobal>

namespace Debugger {
namespace Constants {

// modes and their priorities
const char * const MODE_DEBUG           = "Debugger.Mode.Debug";
const int          P_MODE_DEBUG         = 85;

// common actions
const char * const STOP                 = "Debugger.Interrupt";
const char * const RESET                = "Debugger.Reset";
const char * const STEP                 = "Debugger.StepLine";
const char * const STEPOUT              = "Debugger.StepOut";
const char * const NEXT                 = "Debugger.NextLine";
const char * const REVERSE              = "Debugger.ReverseDirection";

const char * const M_DEBUG_DEBUGGING_LANGUAGES = "Debugger.Menu.View.DebugLanguages";
const char * const M_DEBUG_VIEWS               = "Debugger.Menu.View.Debug";

const char * const C_DEBUGMODE          = "Debugger.DebugMode";
const char * const C_CPPDEBUGGER        = "Gdb Debugger";
const char * const C_QMLDEBUGGER        = "Qml/JavaScript Debugger";

const char * const DEBUGGER_COMMON_SETTINGS_ID = "A.Common";
const char * const DEBUGGER_COMMON_SETTINGS_NAME =
    QT_TRANSLATE_NOOP("Debugger", "General");
const char * const DEBUGGER_SETTINGS_CATEGORY = "O.Debugger";
const char * const DEBUGGER_SETTINGS_TR_CATEGORY =
    QT_TRANSLATE_NOOP("Debugger", "Debugger");
const char * const DEBUGGER_COMMON_SETTINGS_CATEGORY_ICON =
    ":/core/images/category_debug.png";

// dock widget names
const char * const DOCKWIDGET_BREAK = "Debugger.Docks.Break";
const char * const DOCKWIDGET_MODULES = "Debugger.Docks.Modules";
const char * const DOCKWIDGET_REGISTER = "Debugger.Docks.Register";
const char * const DOCKWIDGET_OUTPUT = "Debugger.Docks.Output";
const char * const DOCKWIDGET_SNAPSHOTS = "Debugger.Docks.Snapshots";
const char * const DOCKWIDGET_STACK = "Debugger.Docks.Stack";
const char * const DOCKWIDGET_SOURCE_FILES = "Debugger.Docks.SourceFiles";
const char * const DOCKWIDGET_THREADS = "Debugger.Docks.Threads";
const char * const DOCKWIDGET_WATCHERS = "Debugger.Docks.LocalsAndWatchers";

const char * const DOCKWIDGET_QML_INSPECTOR = "Debugger.Docks.QmlInspector";
const char * const DOCKWIDGET_QML_SCRIPTCONSOLE = "Debugger.Docks.ScriptConsole";

namespace Internal {
    enum { debug = 0 };
#ifdef Q_OS_MAC
    const char * const LD_PRELOAD_ENV_VAR = "DYLD_INSERT_LIBRARIES";
#else
    const char * const LD_PRELOAD_ENV_VAR = "LD_PRELOAD";
#endif

} // namespace Internal

} // namespace Constants


enum DebuggerState
{
    DebuggerNotReady,          // Debugger not started

    EngineSetupRequested,      // Engine starts
    EngineSetupFailed,
    EngineSetupOk,

    InferiorSetupRequested,
    InferiorSetupFailed,

    EngineRunRequested,
    EngineRunFailed,
    InferiorUnrunnable,        // Used in the core dump adapter

    InferiorRunRequested,      // Debuggee requested to run
    InferiorRunOk,             // Debuggee running
    InferiorRunFailed,         // Debuggee running

    InferiorStopRequested,     // Debuggee running, stop requested
    InferiorStopOk,            // Debuggee stopped
    InferiorStopFailed,        // Debuggee not stopped, will kill debugger

    InferiorShutdownRequested,
    InferiorShutdownOk,
    InferiorShutdownFailed,

    EngineShutdownRequested,
    EngineShutdownOk,
    EngineShutdownFailed,

    DebuggerFinished
};

enum DebuggerStartMode
{
    NoStartMode,
    StartInternal,         // Start current start project's binary
    StartExternal,         // Start binary found in file system
    AttachExternal,        // Attach to running process by process id
    AttachCrashedExternal, // Attach to crashed process by process id
    AttachTcf,             // Attach to a running Target Communication Framework agent
    AttachCore,            // Attach to a core file
    AttachToRemote,        // Start and attach to a remote process
    StartRemoteGdb         // Start gdb itself remotely
};

enum DebuggerCapabilities
{
    ReverseSteppingCapability = 0x1,
    SnapshotCapability = 0x2,
    AutoDerefPointersCapability = 0x4,
    DisassemblerCapability = 0x80,
    RegisterCapability = 0x10,
    ShowMemoryCapability = 0x20,
    JumpToLineCapability = 0x40,
    ReloadModuleCapability = 0x80,
    ReloadModuleSymbolsCapability = 0x100,
    BreakOnThrowAndCatchCapability = 0x200,
    ReturnFromFunctionCapability = 0x400,
    CreateFullBacktraceCapability = 0x800,
    AddWatcherCapability = 0x1000,
    WatchpointCapability = 0x2000
};

enum LogChannel
{
    LogInput,                // Used for user input
    LogMiscInput,            // Used for misc stuff in the input pane
    LogOutput,
    LogWarning,
    LogError,
    LogStatus,               // Used for status changed messages
    LogTime,                 // Used for time stamp messages
    LogDebug,
    LogMisc,
    AppOutput,
    AppError,
    AppStuff,
    StatusBar,                // LogStatus and also put to the status bar
    ScriptConsoleOutput
};

enum ModelRoles
{
    DisplaySourceRole = 32,  // Qt::UserRole

    EngineStateRole,
    EngineCapabilitiesRole,
    EngineActionsEnabledRole,
    RequestActivationRole,

    // Running
    RequestExecContinueRole,
    RequestExecInterruptRole,
    RequestExecResetRole,
    RequestExecStepRole,
    RequestExecStepOutRole,
    RequestExecNextRole,
    RequestExecRunToLineRole,
    RequestExecRunToFunctionRole,
    RequestExecReturnFromFunctionRole,
    RequestExecJumpToLineRole,
    RequestExecWatchRole,
    RequestExecSnapshotRole,
    RequestExecFrameDownRole,
    RequestExecFrameUpRole,
    RequestExecDetachRole,
    RequestExecExitRole,
    RequestOperatedByInstructionTriggeredRole,
    RequestExecuteCommandRole,

    // Breakpoints
    BreakpointEnabledRole,
    BreakpointUseFullPathRole,
    BreakpointFunctionNameRole,
    BreakpointFileNameRole,
    BreakpointConditionRole,
    BreakpointIgnoreCountRole,
    BreakpointThreadSpecRole,
    RequestActivateBreakpointRole,
    RequestRemoveBreakpointByIndexRole,
    RequestSynchronizeBreakpointsRole,
    RequestBreakByFunctionRole,
    RequestBreakByFunctionMainRole,
    RequestBreakpointRole,
    RequestToggleBreakpointRole,
    RequestToggleBreakpointEnabledRole,
    RequestContextMenuRole,

    // Locals and Watchers
    LocalsINameRole,
    LocalsExpressionRole,
    LocalsExpandedRole,     // The preferred expanded state to the view
    LocalsTypeFormatListRole,
    LocalsTypeFormatRole,   // Used to communicate alternative formats to the view
    LocalsIndividualFormatRole,
    LocalsAddressRole,      // Memory address of variable as quint64
    LocalsRawValueRole,     // Unformatted value as string
    LocalsPointerValueRole, // Pointer value (address) as quint64
    LocalsIsWatchpointAtAddressRole,
    LocalsIsWatchpointAtPointerValueRole,
    RequestShowInEditorRole,
    RequestWatchPointRole,
    RequestToggleWatchRole,
    RequestToolTipByExpressionRole,
    RequestClearCppCodeModelSnapshotRole,
    RequestAssignValueRole,
    RequestAssignTypeRole,
    RequestWatchExpressionRole,
    RequestRemoveWatchExpressionRole,

    // Stack
    StackFrameAddressRole,
    RequestActivateFrameRole,
    RequestReloadFullStackRole,
    RequestShowMemoryRole,
    RequestShowDisassemblerRole,

    // Threads
    CurrentThreadIdRole,
    RequestSelectThreadRole,

    // Modules
    RequestReloadModulesRole,
    RequestExamineModulesRole,
    RequestModuleSymbolsRole,
    RequestAllSymbolsRole,
    RequestOpenFileRole,

    // Registers
    RegisterNumberBaseRole,  // Currently used number base
    RegisterAddressRole,     // Start value for opening memory view
    RegisterChangedRole,     // Used for painting changed values
    RequestSetRegisterRole,
    RequestReloadRegistersRole,

    // Snapshots
    SnapshotCapabilityRole,
    RequestCreateSnapshotRole,
    RequestActivateSnapshotRole,
    RequestRemoveSnapshotRole,

    // Sources
    RequestReloadSourceFilesRole,
};

enum DebuggerEngineType
{
    NoEngineType      = 0,
    GdbEngineType     = 0x01,
    ScriptEngineType  = 0x02,
    CdbEngineType     = 0x04,
    PdbEngineType     = 0x08,
    TcfEngineType     = 0x10,
    QmlEngineType     = 0x20,
    QmlCppEngineType     = 0x40,
    AllEngineTypes = GdbEngineType
        | ScriptEngineType
        | CdbEngineType
        | PdbEngineType
        | TcfEngineType
        | QmlEngineType
        | QmlCppEngineType
};

enum DebuggerLanguage
{
    AnyLanguage       = 0x0,
    CppLanguage      = 0x1,
    QmlLanguage      = 0x2
};
Q_DECLARE_FLAGS(DebuggerLanguages, DebuggerLanguage)

} // namespace Debugger

#endif // DEBUGGERCONSTANTS_H

