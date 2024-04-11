namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            Controlled Z([qs[0]], qs[1]);
            H(qs[0]);
            H(qs[1]);
            mutable ans = 0;
            if(M(qs[0]) == One){
                set ans = ans + 2;
            }
            if(M(qs[1]) == One){
                set ans = ans + 1;
            }

            if(ans == 0 or ans == 3){
                set ans = 3 - ans;
            }
            return ans;
        }
    }
}