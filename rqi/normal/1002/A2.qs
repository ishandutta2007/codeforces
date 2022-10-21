namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (qs : Qubit[], bits : Bool[]) : Unit {
        // your code here
        mutable N = Length(qs);
        mutable fpos = -1;
        mutable i = 0;
        repeat{
            if(bits[i] == true){
                set fpos = i;
            }
            set i = i+1;
        }
        until(fpos != -1);
        H(qs[fpos]);
        set i = 0;
        repeat{
            if(bits[i] == true and i != fpos){
                Controlled X([qs[fpos]], qs[i]);
            }
            set i = i+1;
        }
        until(i == N);
    }
}