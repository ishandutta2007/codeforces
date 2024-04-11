namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q: Qubit) : Unit {
        let current = M(q);
        if (desired != current) {
            X(q);
        }
    }

    operation Solve (qs : Qubit[]) : Unit {
        let op = StatePreparationPositiveCoefficients([1.0, 1.0, 1.0, 0.0]);
        op(BigEndian(qs));
    }

    operation Test () : Unit {
    }
}