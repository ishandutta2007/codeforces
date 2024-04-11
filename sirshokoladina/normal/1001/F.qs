namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
        	mutable d = 0;
        	for (i in 0..Length(qs) - 1) {
        		if (bits0[i] != bits1[i]) {
        			set d = i;
        		}
        	}
        	mutable res = false;
        	if (M(qs[d]) == One) {
        		set res = true;
        	}
        	if (res == bits0[d]) {
        		return 0;
        	}
        	return 1;
        }
    }
}