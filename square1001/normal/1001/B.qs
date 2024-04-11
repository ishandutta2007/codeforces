namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], sign : Int) : ()
    {
        body
        {
            if(sign == 2 || sign == 3) {
                X(qs[1]);
            }
            if(sign == 1 || sign == 3) {
                X(qs[0]);
            }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }
}