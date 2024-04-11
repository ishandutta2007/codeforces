namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            // your code here
            Controlled X(x, y);
            for(i in 0..2){
                X(x[i]);
                Controlled X(x, y);
                X(x[i]);
            }
        }
    }
}