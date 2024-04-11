namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            // your code here
            mutable b = new Int[N];
            using(qs = Qubit[N+1]){
                Uf(qs[0..N-1], qs[N]);
                if((M(qs[N]) == Zero) == (N % 2 == 0)){
                    set b w/= 0 <- 0;
                }else{
                    set b w/= 0 <- 1;
                }

                for(i in 1..N-1){
                    set b w/= i <- 0;
                }
                ResetAll(qs);
            }
            return b;
        }
    }
}