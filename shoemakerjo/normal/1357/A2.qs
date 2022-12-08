namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable res = 0;
        using (qs = (Qubit[2])) {
            X(qs[0]);
            unitary(qs);
            let a = M(qs[0]) == Zero ? 0 | 1;
            let b = M(qs[1]) == Zero ? 0 | 1;
            Reset(qs[0]);
            Reset(qs[1]);
            X(qs[1]);
            unitary(qs);
            let c = M(qs[0]) == Zero ? 0 | 1;
            let d = M(qs[1]) == Zero ? 0 | 1;
            if (a == 1 and b == 0 and c == 0 and d == 1) {
                set res = 0;
            }
            if (a == 1 and b == 1 and c == 0 and d == 1) {
                set res = 1;
            }
            if (a == 1 and b == 0 and c == 1 and d == 1) {
                set res = 2;
            }
            if (a == 0 and b == 1 and c == 1 and d == 0) {
                set res = 3;
            }
            Reset(qs[0]);
            Reset(qs[1]);
        }
        return res;
    }
}