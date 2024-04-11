namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
        	mutable count=0;
        	for(i in 0..Length(qs)-1){
        		if(M(qs[i])==One){
        			set count=count+1;
        		}
        	}
        	if(count==0){
        		return 0;
        	}
        	if(count==Length(qs)){
        		return 0;
        	}
        	return 1;
        }
    }
}