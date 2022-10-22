namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            // your code here
            mutable ans = 0;
            for(i in 0..Length(qs) - 1){
                if((M(qs[i]) == One) != bits0[i]){
                    set ans = 1;
                }
            }
            
            return ans;
        }
    }
}