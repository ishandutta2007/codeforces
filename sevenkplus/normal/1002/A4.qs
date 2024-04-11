namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Math;

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

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        if (N == 1) {
            X(qs[0]);
            return ();
        }
        Solve(qs[0..N/2-1]);
        using (q = Qubit()) {
            H(q);
            for (i in 0..N/2-1) {
                Controlled SWAP([q], (qs[i], qs[i+N/2]));
            }
            for (i in 0..N/2-1) {
                CNOT(qs[i+N/2], q);
            }
        }
    }

    operation SolveB1 (qs : Qubit[]) : Int {
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

    operation SolveB2 (qs : Qubit[]) : Int {
        mutable cnt = 0;
        for (i in 0..Length(qs)-1) {
            if (M(qs[i]) == One) {
                set cnt = cnt + 1;
            }
        }
        if (cnt == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    operation SolveB3 (qs : Qubit[]) : Int {
        H(qs[0]);
        H(qs[1]);
        mutable res = 0;
        if (M(qs[0]) == One) {
            set res = res + 2;
        }
        if (M(qs[1]) == One) {
            set res = res + 1;
        }
        return res;
    }

    operation SolveB4 (qs : Qubit[]) : Int {
        H(qs[1]);
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        mutable res = 0;
        if (M(qs[0]) == Zero) {
            set res = res + 1;
        }
        if (M(qs[1]) == Zero) {
            set res = res + 2;
        }
        return res;
    }

    operation SolveC1 (q : Qubit) : Int {
        Ry(PI()*0.25, q);
        if (M(q) == One) {
            return 1;
        } else {
            return 0;
        }
    }

    operation SolveC2 (q : Qubit) : Int {
        if (RandomInt(2) == 0) {
            if (M(q) == One) {
                return 1;
            } else {
                return -1;
            }
        } else {
            H(q);
            if (M(q) == One) {
                return 0;
            } else {
                return -1;
            }
        }
    }

    operation SolveD1 (x : Qubit[], y : Qubit, b : Int[]) : Unit {
        for (i in 0..Length(x)-1) {
            if (b[i] == 1) {
                CNOT(x[i], y);
            }
        }
    }

    operation SolveD2 (x : Qubit[], y : Qubit, b : Int[]) : Unit {
        for (i in 0..Length(x)-1) {
            if (b[i] == 0) {
                X(y);
            }
            CNOT(x[i], y);
        }
    }

    operation SolveD3 (x : Qubit[], y : Qubit) : Unit {
        CCNOT(x[0], x[1], y);
        CCNOT(x[0], x[2], y);
        CCNOT(x[1], x[2], y);
    }

    operation SolveE1 (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
        mutable res = new Int[N];
        using (qs = Qubit[N]) {
            for (i in 0..N-1) {
                H(qs[i]);
            }
            using (q = Qubit()) {
                X(q);
                H(q);
                Uf(qs, q);
                for (i in 0..N-1) {
                    H(qs[i]);
                    if (M(qs[i]) == Zero) {
                        set res[i] = 0;
                    } else {
                        set res[i] = 1;
                    }
                }
                Reset(q);
            }
            ResetAll(qs);
        }
        return res;
    }

    operation SolveE2 (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
        mutable res = new Int[N];
        for (i in 0..N-1) {
            set res[i] = 0;
        }
        using (qs = Qubit[N]) {
            for (i in 0..N-1) {
                X(qs[i]);
            }
            using (q = Qubit()) {
                Uf(qs, q);
                if (M(q) == One) {
                    set res[0] = 1;
                }
                Reset(q);
            }
            ResetAll(qs);
        }
        return res;
    }

    operation Test () : Unit {
    }
}