namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[1]);
            unitary(qs);
            if (M(qs[0]) == One){
                Reset(qs[0]);
                Reset(qs[1]);
                return 1;
            } else {
                Reset(qs[0]);
                Reset(qs[1]);
                return 0;
            }
        }

    }
}