namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (qs : Qubit[]) : Int {
        // your code here
        mutable ans = false;
        mutable i = 0;
        repeat{
            let a = M(qs[i]);
            if(a == One){
                set ans = true;
            }
            set i = i+1;
        }
        until(i == Length(qs));
        if(ans == false){
            return 0;
        }
        return 1;
    }
}