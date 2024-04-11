namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
 
    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
    	let N = Length(qs);
		mutable val = new Int[4];
		using (anc = Qubit[2]) {
			ApplyToEach(H, anc);
			for (i in 0..3) {
				for (j in 0..N - 1){
					if (bits[i][j]) {
						(ControlledOnInt(i, X))(anc, qs[j]);
						set val[i] = val[i] + (1 <<< j);
					}
				}
			}
			for (i in 0..3) {
				for (t in 0..1) {
					if ((i &&& (1 <<< t)) > 0) {
						(ControlledOnInt(val[i], X))(qs, anc[t]);
					}
				}
			}
		}
	}
}