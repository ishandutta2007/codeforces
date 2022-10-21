namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        // your code here
        let a = [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
        let b = [3.142399999999995];
        let c = 0.0010999999999999899;
        return (a,(b,c));
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