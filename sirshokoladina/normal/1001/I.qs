namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
 
	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
	{
		body
		{
			mutable res = true;
			using (qs = Qubit[N + 1]) {
				X(qs[N]);
				for (q in qs) {
					H(q);
				}
				Uf(qs[0..N - 1], qs[N]);
				for (q in qs) {
					H(q);
				}

				for (i in 0..N - 1) {
					if (M(qs[i]) == One) {
						set res = false;
					}
				}
				ResetAll(qs);
			}
			return res;
		}
	}
}