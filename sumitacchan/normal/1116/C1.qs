namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            // your code here
            let N = Length(x);
            for(i in 0..N-2){
                CNOT(x[i+1], x[i]);
            }
            Controlled X(x[0..N-2], y);
            for(i in 0..N-2){
                CNOT(x[N-1-i], x[N-2-i]);
            }
        }
        adjoint auto;
    }
}