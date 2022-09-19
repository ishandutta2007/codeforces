namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (x : Qubit[], y : Qubit) : ()
	{
		body
		{
			(Controlled X)([x[0], x[1]], y);
			(Controlled X)([x[0], x[2]], y);
			(Controlled X)([x[1], x[2]], y);
		}
	}
}