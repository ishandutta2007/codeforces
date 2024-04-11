namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation incMod3 (qs : Qubit[]) : Unit is Adj + Ctl {
        X(qs[1]);
        Controlled X([qs[1]], qs[0]);
        X(qs[1]);
        X(qs[0]);
        Controlled X([qs[0]], qs[1]);
        X(qs[0]);
    }

    operation dostuff (inputs : Qubit[], qs : Qubit[]) : Unit is Adj + Ctl {
        for (i in 0 .. 2 .. Length(inputs)-1) {
            Controlled incMod3([inputs[i]], qs);                
        }
        for (i in 1 .. 2 .. Length(inputs)-1) {
            Controlled Adjoint incMod3([inputs[i]], qs);
        }
        X(qs[0]);
        X(qs[1]);
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        // your code here
        using (qs = (Qubit[2])) {
            dostuff(inputs, qs);
            Controlled X(qs, output);
            Adjoint dostuff(inputs, qs);
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