namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        // your code here
        
        let N = Length(inputs);
        using(t = Qubit[2]){
            for(i in 0..N-1){
                if(i % 2 == 0){
                    X(t[1]);
                    Controlled X([inputs[i], t[1]], t[0]);
                    X(t[1]);
                    X(t[0]);
                    Controlled X([inputs[i], t[0]], t[1]);
                    X(t[0]);
                }else{
                    X(t[0]);
                    Controlled X([inputs[i], t[0]], t[1]);
                    X(t[0]);
                    X(t[1]);
                    Controlled X([inputs[i], t[1]], t[0]);
                    X(t[1]);
                }
            }
            X(t[0]);
            X(t[1]);
            Controlled X(t, output);
            X(t[0]);
            X(t[1]);

            for(i in 0..N-1){
                if(i % 2 == 1){
                    X(t[1]);
                    Controlled X([inputs[i], t[1]], t[0]);
                    X(t[1]);
                    X(t[0]);
                    Controlled X([inputs[i], t[0]], t[1]);
                    X(t[0]);
                }else{
                    X(t[0]);
                    Controlled X([inputs[i], t[0]], t[1]);
                    X(t[0]);
                    X(t[1]);
                    Controlled X([inputs[i], t[1]], t[0]);
                    X(t[1]);
                }
            }
        }
    }
}