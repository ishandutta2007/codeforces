namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let x1 = M(qs[0]);
            let x2 = M(qs[1]);
            if(x1 == Zero && x2 == Zero) {
                return 0;
            }
            elif(x1 == One && x2 == Zero) {
                return 1;
            }
            elif(x1 == Zero && x2 == One) {
                return 2;
            }
            else {
                return 3;
            }
        }
    }
}