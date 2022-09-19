namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (q : Qubit) : Int
	{
		body
		{
			mutable b = 0;
			using (c = Qubit()) {
				H(c);
				if (M(c) == One) {
					set b = 1;
				}
				Reset(c);
			}
			if (b == 1) {
				H(q);
			}
			if (M(q) == One) {
				return 1 - b;
			}
			return -1;
		}
	}
}