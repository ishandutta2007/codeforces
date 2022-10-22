namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = -1;
        using(t = Qubit[2]){
            H(t[0]);
            Controlled unitary([t[0]], (2.0 * 3.14159265359, t[1]));
            H(t[0]);
            if(M(t[0]) == Zero){
                set ans = 1;
            }else{
                set ans = 0;
            }
            ResetAll(t);
        }
        return ans;
    }
}