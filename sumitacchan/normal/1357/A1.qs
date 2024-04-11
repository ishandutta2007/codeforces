namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using(t = Qubit[2]){
            X(t[0]);
            unitary(t);
            if(M(t[1]) == Zero){
                set ans = 1;
            }
            ResetAll(t);
        }
        return ans;
    }
}