namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        let N = Length(qs);
        mutable i = 0;
        repeat{
            H(qs[i]);
            set i = i+1;
        }
        until(i == N);
    }
}