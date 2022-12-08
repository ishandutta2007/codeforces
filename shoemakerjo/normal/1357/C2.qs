
namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        // your code here
        using (q = Qubit()) {
            repeat {
                if (parity == 1) {
                    X(q);
                }
                for (index in 0 .. Length(qs)-1) {
                    H(qs[index]);
                }
                for (index in 0 .. Length(qs)-1) {
                    CNOT(qs[index], q);
                }
                // Controlled X(qs, q);
            } until (M(q) == Zero)
            fixup {
                ResetAll(qs);
                Reset(q);
            }
        }
    }
}


//A6 Below
// namespace Solution {
//     open Microsoft.Quantum.Intrinsic;

//     operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
//         // your code here
//         mutable res = 0;
//         using (qs = (Qubit[2])) {

//         }
//     }
// }