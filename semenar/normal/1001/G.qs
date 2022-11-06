namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            // Why not just entangle y with x[k]?
			CNOT(x[k], y);
        }
    }
}