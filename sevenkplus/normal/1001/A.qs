namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q: Qubit) : Unit {
        let current = M(q);
        if (desired != current) {
            X(q);
        }
    }

    operation Solve (q : Qubit, sign : Int) : Unit {
        if (sign == -1) {
            X(q);
        }
        H(q);
    }

    operation Test () : Unit {
        using (q = Qubit()) {
            Set(Zero, q);
            Solve(q, 1);
        }
    }
}