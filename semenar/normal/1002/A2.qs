namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            let n = Length(qs);
			mutable pos = -1;

			for (i in 0..(n - 1)) {
				if (bits[i]) {
					if (pos == -1) {
						set pos = i;
						H(qs[i]);
					}
					else {
						CNOT(qs[pos], qs[i]);
					}
				}
			}
        }
    }
}