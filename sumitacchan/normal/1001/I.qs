namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            // your code here
            mutable ans = true;
            using(x = Qubit[N + 1]){
                X(x[N]);
                ApplyToEach(H, x);
                Uf(x[0..N-1], x[N]);
                ApplyToEach(H, x);

                for(q in x[0..N-1]){
                    if(M(q) == One){
                        set ans = false;
                    }
                }

                ResetAll(x);
            }
            return ans;
        }
    }
}