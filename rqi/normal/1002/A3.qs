namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        // your code here
        mutable i = 0;
        mutable onearr = -1;
        mutable onepos = -1;

        repeat{
            if(bits0[i] != bits1[i]){
                if(onepos == -1){
                    if(bits0[i] == true){
                        set onearr = 0;
                        set onepos = i;
                    }
                    else{
                        set onearr = 1;
                        set onepos = i;
                    }
                    H(qs[i]);
                }
                else{
                    Controlled X([qs[onepos]], qs[i]);
                    if(onearr == 0){
                        if(bits0[i] == false){
                            X(qs[i]);
                        }
                    }
                    else{
                        if(bits1[i] == false){
                            X(qs[i]);
                        }
                    }
                }
            }
            elif(bits0[i] == true){
                X(qs[i]);
            }
            set i = i+1;
        }
        until(i == Length(qs));
    }
}