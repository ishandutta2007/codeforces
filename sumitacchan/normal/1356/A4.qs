namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using(q = Qubit[2]){
            unitary(q);
            if(M(q[1]) == Zero){
                set ans = 1;
            }
            ResetAll(q);
        }
        return ans;
    }
}