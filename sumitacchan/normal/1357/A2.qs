namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = -1;
        using(t = Qubit[2]){
            X(t[0]);
            unitary(t);
            if(M(t[1]) == One){
                if(M(t[0]) == Zero){
                    set ans = 3;
                }else{
                    set ans = 1;
                }
            }
            ResetAll(t);
        }

        using(t = Qubit[2]){
            X(t[1]);
            unitary(t);
            if(ans == -1){
                if(M(t[0]) == Zero){
                    set ans = 0;
                }else{
                    set ans = 2;
                }
            }
            ResetAll(t);
        }

        return ans;
    }
}