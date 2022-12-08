namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Increment(qs : Qubit[]) : Unit is Adj + Ctl {
        let n = Length(qs);
        for (i in n-2 .. -1 .. 0) {
            Controlled X(qs[0 .. i], qs[i+1]);
        }
        X(qs[0]);
    }

    operation dostuff(inputs : Qubit[], qs : Qubit[]) : Unit is Adj + Ctl {
        let n = Length(inputs);
        for (i in 0 .. n-1) {
            Controlled Increment([inputs[i]], qs);
        }
        for (i in 0 .. n-1) {
            X(inputs[i]);
        }
        for (i in 0 .. n-1) {
            Controlled Adjoint Increment([inputs[i]], qs);
        }
        for (i in 0 .. 3) {
            X(qs[i]);
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);
        using (qs = (Qubit[4])) {

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