namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        // your code here
        let N = Length(inputs);
        using(cnt = Qubit[4]){
            for(i in 0..N-1){
                Controlled X([inputs[i], cnt[0], cnt[1], cnt[2]], cnt[3]);
                Controlled X([inputs[i], cnt[0], cnt[1]], cnt[2]);
                Controlled X([inputs[i], cnt[0]], cnt[1]);
                CNOT(inputs[i], cnt[0]);
            }
            
            for(j in 0..3){
                if(((N/2) >>> j) % 2 == 0){
                    X(cnt[j]);
                }
            }
            Controlled X(cnt, output);
            for(j in 0..3){
                if(((N/2) >>> j) % 2 == 0){
                    X(cnt[j]);
                }
            }

            for(i in 0..N-1){
                CNOT(inputs[i], cnt[0]);
                Controlled X([inputs[i], cnt[0]], cnt[1]);
                Controlled X([inputs[i], cnt[0], cnt[1]], cnt[2]);
                Controlled X([inputs[i], cnt[0], cnt[1], cnt[2]], cnt[3]);
            }

            //ResetAll(cnt);
        }
    }
}