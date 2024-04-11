namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable res = 0;
        using (qs = (Qubit[1])) {
            X(qs[0]);
            unitary(qs[0]);
            Z(qs[0]);
            unitary(qs[0]);
            if (M(qs[0]) == Zero) {
                set res = 0;
            }
            else {
                set res = 1;
            }
            Reset(qs[0]);
        }
        return res;
    }
}