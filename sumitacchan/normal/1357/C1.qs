namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        mutable ok = false;
        repeat{
            using(t = Qubit()){
                for(q in qs){
                    H(q);
                }
                Controlled X(qs, t);
                if(M(t) == Zero){
                    set ok = true;
                }else{
                    ResetAll(qs);
                }
                ResetAll([t]);
            }
        }
        until(ok);
    }
}