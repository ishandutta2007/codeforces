namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        // your code here
        mutable ok = false;
        repeat{
            using(t = Qubit()){
                for(q in qs){
                    H(q);
                    CNOT(q, t);
                }
                if((M(t) == Zero) == (parity == 0)){
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