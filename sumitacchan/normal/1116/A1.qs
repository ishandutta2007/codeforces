namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        mutable ok = false;
        repeat{
            H(qs[0]);
            H(qs[1]);
            using(t = Qubit()){
                Controlled X(qs, t);
                if(M(t) == Zero){
                    set ok = true;
                }else{
                    X(qs[0]);
                    X(qs[1]);
                }
                ResetAll([t]);
            }
        }
        until(ok);

    }
}