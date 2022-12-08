
namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        using (q = Qubit()) {
            repeat {
                for (index in 0 .. Length(qs)-1) {
                    H(qs[index]);
                }
                Controlled X(qs, q);
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