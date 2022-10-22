namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            // your code here
            Ry(3.1415926/4.0, q);
            if(M(q) == Zero){
                return 0;
            }else{
                return 1;
            }
        }
    }
}