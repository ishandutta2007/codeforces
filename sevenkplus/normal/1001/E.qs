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

    operation SolveD (q : Qubit) : Int {
        H(q);
        let r = M(q);
        if (r == Zero) {
            return 1;
        } else {
            return -1;
        }
    }

    operation Solve (qs : Qubit[]) : Int {
        CNOT(qs[0], qs[1]);
        mutable r = 0;
        if (SolveD(qs[0]) == -1) {
            set r = r + 1;
        }
        if (M(qs[1]) == One) {
            set r = r + 2;
        }
        return r;
    }

    operation Test () : Unit {
        using (qs = Qubit[2]) {
            SolveB(qs, 3);
            let r = Solve(qs);
            Message($"{r}");
            ResetAll(qs);
        }
    }
}