namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            // your code here
            let N = Length(x);
            using(t = Qubit[2]){
                for(i in 0..N-1){
                    (ControlledOnBitString([true, false], X))([x[i], t[1]], t[0]);
                    (ControlledOnBitString([true, false], X))([x[i], t[0]], t[1]);
                }
                (ControlledOnInt(0, X))(t, y);
                for(i in 0..N-1){
                    (ControlledOnBitString([true, false], X))([x[N-1-i], t[0]], t[1]);
                    (ControlledOnBitString([true, false], X))([x[N-1-i], t[1]], t[0]);
                }
            }
        }
        adjoint auto;
    }
}