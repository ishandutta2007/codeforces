namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Unit {
		using (r = Qubit()) {
			repeat {
				ResetAll(qs);
				H(qs[0]);
				H(qs[1]);
				CCNOT(qs[0], qs[1], r);
				let result = M(r);
				Reset(r);
			} until (result == Zero) 
			fixup {
			}
		}
	}
}