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
        let N = Length(qs);
        for (i in 0..N-1) {
            H(qs[i]);
        }
    }

    operation SolveA2 (qs : Qubit[], bits : Bool[]) : Unit {
        let N = Length(qs);
        mutable first = -1;
        for (i in 0..N-1) {
            if (bits[i]) {
                if (first == -1) {
                    H(qs[i]);
                    set first = i;
                } else {
                    CNOT(qs[first], qs[i]);
                }
            }
        }
    }

    operation SolveA3 (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        let N = Length(qs);
        mutable first = -1;
        for (i in 0..N-1) {
            if (XOR(bits1[i], bits0[i])) {
                if (first == -1) {
                    H(qs[i]);
                    set first = i;
                } else {
                    CNOT(qs[first], qs[i]);
                }
            }
        }
        for (i in 0..N-1) {
            if (bits0[i]) {
                X(qs[i]);
            }
        }
    }

    operation Solve (qs : Qubit[]) : Int {
        mutable res = 0;
        using (q = Qubit()) {
            for (i in 0..Length(qs)-1) {
                CNOT(qs[i], q);
            }
            if (M(q) == One) {
                set res = 1;
            }
            Reset(q);
        }
        return res;
    }

    operation Test () : Unit {
    }
}