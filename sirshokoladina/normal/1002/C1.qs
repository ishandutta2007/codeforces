namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;
 
    operation Solve (q : Qubit) : Int
    {
        body
        {
			Ry(PI() / 4.0, q);
			return (M(q) == Zero) ? 0 | 1;
        }
    }
 
}