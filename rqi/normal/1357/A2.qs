namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable zt = false;
        using(q = Qubit[2]){
            Set(q[0], One);
            Set(q[1], One);
            unitary(q);
            let a1 = M(q[0]);
            let a2 = M(q[1]);
            if(a1 == One and a2 == One){
                set zt = true;
            }
            Set(q[0], Zero);
            Set(q[1], Zero);
        }
        if(zt == true){
            mutable b1 = Zero;
            using(q = Qubit[2]){
                Set(q[0], Zero);
                Set(q[1], One);
                unitary(q);
                set b1 = M(q[0]);
                Set(q[0], Zero);
                Set(q[1], Zero);
                
            }
            if(b1 == One){
                return 3;
            }
            return 0;
        }
        else{
            mutable ans = Zero;
            using(q = Qubit[2]){
                Set(q[0], One);
                unitary(q);
                set ans = M(q[1]);
                Set(q[0], Zero);
                Set(q[1], Zero);
            }
            if(ans == One){
                return 1;
            }
            return 2;
        }
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