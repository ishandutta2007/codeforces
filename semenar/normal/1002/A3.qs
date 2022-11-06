namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let n = Length(qs);
			mutable pos = -1;

			for (i in 0..(n - 1)) {
				if (bits0[i] && bits1[i]) {
					X(qs[i]);
				}
				if (bits0[i] != bits1[i]) {
					if (pos == -1) {
						set pos = i;
						H(qs[i]);
					}
					else {
						if (bits0[i] != bits0[pos]) {
							X(qs[i]);
						}
						CNOT(qs[pos], qs[i]);
					}
				}
			}
        }
    }
}