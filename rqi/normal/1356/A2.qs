namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable b = Zero;
        using (q = Qubit()){
            H(q);
            unitary(q);
            H(q);
            set b = M(q);
            Set(q, Zero);
        }
        if(b == Zero){ return 0; }
        return 1;
    }
}