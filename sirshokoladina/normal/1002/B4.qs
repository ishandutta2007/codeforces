namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int
	{
		body
		{
			H(qs[0]);
			CNOT(qs[1], qs[0]);
			H(qs[1]);
			let a = M(qs[0]);
			let b = M(qs[1]);
			if (b == One) {
				if (a == One) {
					return 0;
				} else {
					return 1;
				}
			} else {
				if (a == One) {
					return 2;
				} else {
					return 3;
				}
			}
		}
	}
}