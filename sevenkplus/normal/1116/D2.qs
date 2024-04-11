namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q: Qubit) : Unit {
        let current = M(q);
        if (desired != current) {
            X(q);
        }
    }

    operation SolveA1 (qs : Qubit[]) : Unit {
        let op = StatePreparationPositiveCoefficients([1.0, 1.0, 1.0, 0.0]);
        op(BigEndian(qs));
    }

    operation SolveD1 (qs : Qubit[]) : Unit {
        H(qs[0]);
    }

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 0..N-1) {
            X(qs[i]);
        }
        for (i in 0..N-2) {
            Controlled H(qs[i+1..N-1], qs[i]);
            H(qs[i]);
        }
        for (i in 0..N-1) {
            X(qs[i]);
        }
    }

    operation Test () : Unit {
    }
}