namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            // your code here
            ApplyToEach(H, qs);
        }
    }
}