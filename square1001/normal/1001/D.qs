namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let t = M(q);
            if(t == Zero) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
}