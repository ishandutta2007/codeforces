namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (qs : Qubit[]) : Unit {
        for (i in 0 .. Length(qs) - 1) {
            for (j in 0 .. i - 1) {
                Controlled H ([qs[i]], qs[j]);
                Controlled R1 ([qs[i]], (ToDouble(i) / 6.0, qs[j]));
            }
        }
    }
}