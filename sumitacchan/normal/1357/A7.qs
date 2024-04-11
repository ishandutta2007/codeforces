namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using(q = Qubit[2]){
            H(q[0]);
            Controlled unitary([q[0]], q[1]);
            Controlled unitary([q[0]], q[1]);
            H(q[0]);
            if(M(q[0]) == One){
                set ans = 1;
            }
            ResetAll(q);
        }

        using(q = Qubit[2]){
            H(q[0]);
            Controlled unitary([q[0]], q[1]);
            if(ans == 0){
                Controlled Y([q[0]], q[1]);
            }else{
                Controlled Z([q[0]], q[1]);
                Controlled X([q[0]], q[1]);
            }
            H(q[0]);
            if(M(q[0]) == One){
                set ans = ans + 2;
            }
            ResetAll(q);
        }
        return ans;
    }
}