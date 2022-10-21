namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable b = Zero;
        using (q = Qubit[2]){
            H(q[0]);
            CNOT(q[0], q[1]);
            mutable c = 3.1415926535;
            set c = c+c;
            Controlled unitary([q[0]], (c, q[1]));
            Controlled Z([q[0]], q[1]);
            CNOT(q[0], q[1]);
            H(q[0]);
            set b = M(q[0]);
            Set(q[0], Zero);
            Set(q[1], Zero);
        }
        if(b == Zero){
            return 0;
        }
        return 1;
    }
 
    // @EntryPoint()
    // operation HelloQ() : Unit {
    //     Message("Hello quantum world!");
    //     using (q = Qubit[3]) {
    //         Set(q[0],One);
    //         Set(q[1],One);
    //         for (i in 0..2) {
    //             Set(q[i],Zero);
    //         }
    //     }
    // }
}