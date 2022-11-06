namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable ones_cnt = 0;
			let n = Length(qs);

			for (i in 0..(n - 1)) {
				if (M(qs[i]) == One) {
					set ones_cnt = ones_cnt + 1;
				}
			}

			if (ones_cnt == 1) {
				return 1;
			}
			else {
				return 0;
			}
        }
    }
}