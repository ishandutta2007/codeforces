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

    operation SolveC1 (q : Qubit) : Int {
        Ry(PI()*0.25, q);
        if (M(q) == One) {
            return 1;
        } else {
            return 0;
        }
    }

    operation Solve (q : Qubit) : Int {
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

    operation Test () : Unit {
        mutable cnt1 = 0;
        mutable cnt2 = 0;
        for (i in 0..999) {
            using (q = Qubit()) {
                if (i >= 500) {
                    H(q);
                }
                let ans = Solve(q);
                if (i < 500 && ans == 0) {
                    set cnt1 = cnt1 + 1;
                }
                if (i >= 500 && ans == 1) {
                    set cnt2 = cnt2 + 1;
                }
                Reset(q);
            }
        }
        Message($"{cnt1} {cnt2}");
    }
}