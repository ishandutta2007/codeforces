namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int
	{
		body
		{
			mutable cnt = 0;
			for (q in qs) {
				if (M(q) == One) {
					set cnt = cnt + 1;
				}
			}
			if (cnt == 0 || cnt == Length(qs)) {
				return 0;
			}
			return 1;
		}
	}
}