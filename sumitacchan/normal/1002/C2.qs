namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            // your code here
            let i = Random([0.5, 0.5]);
            if(i == 0){
                H(q);
                if(M(q) == Zero){
                    return -1;
                }else{
                    return 0;
                }
            }else{
                if(M(q) == Zero){
                    return -1;
                }else{
                    return 1;
                }
            }
        }
    }
}