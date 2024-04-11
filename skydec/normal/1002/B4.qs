namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[1]);
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            mutable ans=0;
            if(M(qs[0])==Zero){
            	set ans=ans+1;
            }
            if(M(qs[1])==Zero){
            	set ans=ans+2;
            }
            return ans;
        }
    }
}