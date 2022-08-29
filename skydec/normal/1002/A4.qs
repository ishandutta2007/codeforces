namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let n=Length(qs);
         	X(qs[0]);
         	mutable s=1;
         	for(rd in 0..n){
         		if(s!=n){
         			using(tmp=Qubit[1]){
         				H(tmp[0]);
         				for(i in 0..s-1){
         					CCNOT(tmp[0],qs[i],qs[i+s]);
         					CCNOT(tmp[0],qs[i+s],qs[i]);
         				}
         				for(i in 0..s-1){
         					CNOT(qs[i+s],tmp[0]);
         				}
         			}
         			set s=s*2;
         		}
         	}
        }
    }
}