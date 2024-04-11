namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            X(q[1]);
            unitary(q);
            if (M(q[0]) == One){
                if (M(q[1]) == One){
                    Reset(q[0]);
                    Reset(q[1]);
                    return 2;
                } else {
                    Reset(q[0]);
                    Reset(q[1]);
                    return 3;
                }
            } else {
                Reset(q[0]);
                Reset(q[1]);
                X(q[0]);
                unitary(q);
                if (M(q[1]) == One){
                    Reset(q[0]);
                    Reset(q[1]);
                    return 1;
                } else {
                    Reset(q[0]);
                    Reset(q[1]);
                    return 0;
                }
            }
        }   
 
    }
}