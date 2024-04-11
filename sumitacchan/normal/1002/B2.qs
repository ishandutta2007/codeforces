namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            let res = M(qs[0]);
            mutable ans = 0;
            for(i in 1..Length(qs)-1){
                if(M(qs[i]) != res){
                    set ans = 1;
                }
            }
            return ans;
        }
    }
}