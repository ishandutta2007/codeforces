namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using(q = Qubit[2]){
            H(q[0]);
            CNOT(q[0], q[1]);
            unitary(q[1]);
            CNOT(q[0], q[1]);
            H(q[0]);

            if(M(q[0]) == One){
                set ans = ans + 2;
                X(q[1]);
            }
            if(M(q[1]) == One){
                set ans = ans + 1;
            }
            ResetAll(q);
        }
        return ans;
    }
}