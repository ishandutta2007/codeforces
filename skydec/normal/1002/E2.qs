namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
        	mutable r=new Int[N];
            using(qs=Qubit[N+1]){
            	for(i in 0..N){
            		Reset(qs[i]);
            	}
            	Uf(qs[0..N-1],qs[N]);
            	if(N%2==1){
            		X(qs[N]);
            	}
            	if(M(qs[N])==One){
            		set r[0]=1;
            	}
            	else{
            		set r[0]=0;
            	}
            	for(i in 0..N){
            		Reset(qs[i]);
            	}
            }
            return r;
        }
    }
}