namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            // your code here
            X(qs[0]);

            let N = Length(qs);
            mutable sz = 1;
            while(sz < N){
                for(i in 0..sz-1){
                    Controlled H([qs[i]], qs[i + sz]);
                    CNOT(qs[i + sz], qs[i]);
                }
                set sz = sz * 2;
            }
        }
    }
}