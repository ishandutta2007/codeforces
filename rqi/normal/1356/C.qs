namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        repeat {
            Set(qs[0], Zero);
            Set(qs[1], Zero);
            H(qs[0]);
            H(qs[1]);
            mutable b = Zero;
            using(q = Qubit()){
                Controlled X(qs, q);
                set b = M(q);
                Set(q, Zero);
            }
        }
        until (b == Zero)
        fixup {}
        X(qs[0]);
        X(qs[1]);

    }
}