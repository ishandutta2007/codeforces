namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using(q = Qubit()){
            H(q);
            unitary(q);
            H(q);
            if(M(q) == One){
                set ans = 1;
            }
            ResetAll([q]);
        }
        return ans;
    }
}