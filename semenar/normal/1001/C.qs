namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
			let n = Length(qs);
			// Make Hadamard
			H(qs[0]);
			// Entangle others
			for (i in 1..(n - 1)) {
				CNOT(qs[0], qs[i]);
			}
        }
    }
}