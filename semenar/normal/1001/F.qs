namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let n = Length(qs);
			for (i in 0..(n - 1)) {
				if (bits0[i] != bits1[i]) {
					mutable ans = 0;
					if (bits0[i]) {
						set ans = 1 - ans;
					}
					if (M(qs[i]) == One) {
						set ans = 1 - ans;
					}
					return ans;
				}
			}
			return -1;
        }
    }
}