namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
			// Disentangle qubits
			CNOT(qs[0], qs[1]);

			// Destroy superposition
			H(qs[0]);

			// Calculate answer
			mutable ans = 0;
			if (M(qs[0]) == One) {
				set ans = ans + 1;
			}
			if (M(qs[1]) == One) {
				set ans = ans + 2;
			}
			return ans;
        }
    }
}