namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable b = Zero;
        using(q = Qubit[2]){
            unitary(q);
            set b = M(q[1]);
            Set(q[0], Zero);
            Set(q[1], Zero);
        }
        if(b == One){return 0;}
        return 1;

        // mutable b = Zero;
        // using (q = Qubit()){
        //     H(q);
        //     unitary(q);
        //     unitary(q);
        //     H(q);
        //     set b = M(q);
        //     Set(q, Zero);
        // }
        // if(b == Zero){ return 0; }
        // return 1;
    }
}