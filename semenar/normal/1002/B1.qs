namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable zero_state = true;
			let n = Length(qs);

			for (i in 0..(n - 1)) {
				if (M(qs[i]) == One) {
					set zero_state = false;
				}
			}

			if (zero_state) {
				return 0;
			}
			else {
				return 1;
			}
        }
    }
}