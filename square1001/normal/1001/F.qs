namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let N = Length(qs);
            for(i in 0 .. N-1) {
                if(bits0[i] != bits1[i]) {
                    let x = M(qs[i]);
                    if(x == Zero) {
                        if(bits0[i]) {
                            return 1;
                        }
                        else {
                            return 0;
                        }
                    }
                    else {
                        if(bits0[i]) {
                            return 0;
                        }
                        else {
                            return 1;
                        }
                    }
                }
            }
            return -1;
        }
    }
}