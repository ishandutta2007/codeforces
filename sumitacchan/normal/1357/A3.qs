namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = -1;
        using(t = Qubit()){
            unitary(t);
            X(t);
            unitary(t);

            if(M(t) == One){
                set ans = 1;
            }else{
                set ans = 0;
            }
            ResetAll([t]);
        }
        return ans;
    }
}