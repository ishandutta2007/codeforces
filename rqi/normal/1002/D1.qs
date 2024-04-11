namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : Unit {
        mutable i = 0;
        repeat{
            if(b[i] == 1){
                CNOT(x[i], y);
                
            }
            set i = i+1;
        }
        until(i == Length(x));

    }
}