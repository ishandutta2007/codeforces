namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : ()
	{
		body
		{
			let N = Length(qs) / 2;
			if (N < 1) {
				X(qs[0]);
				return ();
			}
			Solve(qs[0..N-1]);
			using (q = Qubit()) {
				H(q);
				for (i in 0..N-1) {
					(Controlled SWAP)([q], (qs[i], qs[i + N]));
				}
				for (i in 0..N-1) {
					CNOT(qs[i + N], q);
				}
			}
		}
	}
}