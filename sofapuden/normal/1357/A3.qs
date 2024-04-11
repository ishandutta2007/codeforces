namespace Solution {

    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(q = Qubit()){
            unitary(q);
            X(q);
            unitary(q);
            return ResultArrayAsInt([MResetZ(q)]);

        }
       
    }
}