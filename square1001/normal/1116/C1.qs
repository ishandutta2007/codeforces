namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            for(i in 0 .. N - 2) {
                CNOT(x[i + 1], x[i]);
            }
            Controlled X(x[0 .. N - 2], y);
            for(i in 0 .. N - 2) {
                CNOT(x[N - i - 1], x[N - i - 2]);
            }
        }
        adjoint auto;
    }
}