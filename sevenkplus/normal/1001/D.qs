namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q: Qubit) : Unit {
        let current = M(q);
        if (desired != current) {
            X(q);
        }
    }

    operation SolveA (q : Qubit, sign : Int) : Unit {
        if (sign == -1) {
            X(q);
        }
        H(q);
    }

    operation SolveB (qs : Qubit[], index : Int) : Unit {
        if (index % 2 == 1) {
            X(qs[0]);
        }
        H(qs[0]);
        CNOT(qs[0], qs[1]);
        if (index >= 2) {
            X(qs[1]);
        }
    }

    operation SolveC (qs : Qubit[]) : Unit {
        let N = Length(qs);
        H(qs[0]);
        for (i in 1..N-1) {
            CNOT(qs[0], qs[i]);
        }
    }

    operation Solve (q : Qubit) : Int {
        H(q);
        let r = M(q);
        if (r == Zero) {
            return 1;
        } else {
            return -1;
        }
    }

    operation Test () : Unit {
        using (q = Qubit()) {
            Set(One, q);
            H(q);
            let r = Solve(q);
            Message($"{r}");
            Reset(q);
        }
    }
}