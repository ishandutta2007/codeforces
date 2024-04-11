namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], index : Int) : Unit {
        if (index % 2 == 1) {
            X(qs[0]);
        }
        H(qs[0]);
        CNOT(qs[0], qs[1]);
        if (index >= 2) {
            X(qs[1]);
        }
    }

    operation Test () : Unit {
    }
}