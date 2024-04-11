namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            // your code here
            H(qs[0]);
            let N = Length(qs);
            for(i in 1..N-1){
                CNOT(qs[0], qs[i]);
            }
        }
    }
}