namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable res = 0;
        using (qs = (Qubit[2])) {
            H(qs[0]);
            Controlled Z(qs[0 .. 0], qs[1]);
            Controlled unitary(qs[0 .. 0], (2.0*PI(), qs[1]));
            H(qs[0]);
            if (M(qs[0]) == Zero) {
                set res = 1;
            }
            else {
                set res = 0;
            }
            Reset(qs[0]);
            Reset(qs[1]);
        }
        return res;
    }
}