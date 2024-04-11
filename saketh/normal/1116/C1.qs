namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            for (i in 0 .. Length(x) - 1) {
                if (i % 2 == 1) {
                    X(x[i]);
                }
            }

            (ControlledOnInt(0, X))(x, y);
            MultiX(x);
            (ControlledOnInt(0, X))(x, y);
            MultiX(x);

            for (i in 0 .. Length(x) - 1) {
                if (i % 2 == 1) {
                    X(x[i]);
                }
            }
        }
        adjoint auto;
    }
}