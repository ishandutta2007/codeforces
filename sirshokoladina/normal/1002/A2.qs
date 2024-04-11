namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[], bits : Bool[]) : ()
	{
		body
		{
			using (q = Qubit()) {
				H(q);
				for (i in 0..Length(qs)-1) {
					if (bits[i]) {
						CNOT(q, qs[i]);
					}
				}
				mutable first = true;
				for (i in 0..Length(qs)-1) {
					if (bits[i] && first) {
						CNOT(qs[i], q);
						set first = false;
					}
				}
				Reset(q);
			}
		}
	}
}