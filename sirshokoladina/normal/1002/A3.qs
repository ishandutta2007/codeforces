namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
	{
		body
		{
			mutable d = -1;
			for (i in 0..Length(qs)-1) {
				if (bits0[i] != bits1[i]) {
					if (d == -1) {
						H(qs[i]);
						set d = i;
					} else {
						CNOT(qs[d], qs[i]);
					}
				}
			}
			for (i in 0..Length(qs)-1) {
				if (bits0[i]) {
					X(qs[i]);
				}
			}
		}
	}
}