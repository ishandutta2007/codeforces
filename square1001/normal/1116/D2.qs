namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for(i in 0 .. N - 1) {
            let t = N - i - 1;
            for(j in 0 .. t - 1) {
                Controlled H(qs[t .. N - 1], qs[j]);
            }
            X(qs[t]);
        }
        for(i in 0 .. N - 1) {
            X(qs[i]);
        }
    }
}