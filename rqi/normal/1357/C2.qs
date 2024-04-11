namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        // your code here
        mutable val = Zero;
        if(parity == 1){
            set val = One;
        }

        repeat {
            mutable i = 0;
            repeat{
                Set(qs[i], Zero);
                H(qs[i]);
                set i = i+1;
            }
            until(i == Length(qs));

            mutable b = Zero;
            using(q = Qubit()){
                mutable j = 0;
                repeat{
                    Controlled X([qs[j]], q);
                    set j = j+1;
                }
                until(j == Length(qs));

                set b = M(q);
                Set(q, Zero);
            }
        }
        until (b == val)
        fixup {}
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