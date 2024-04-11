namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
	{
		body
		{
			mutable ans = new Int[N];
			mutable res = 0;
			using (qs = Qubit[N + 1]) {
				Uf(qs[0..N - 1], qs[N]);
				if (M(qs[N]) == One) {
					set res = 1;
				}
				ResetAll(qs);
			}
			set ans[0] = (res + N) % 2;
			return ans;
		}
	}
}