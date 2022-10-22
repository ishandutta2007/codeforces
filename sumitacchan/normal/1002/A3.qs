namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            // your code here
            mutable i0 = 0;
            let N = Length(qs);

            while(bits0[i0] == bits1[i0]){
                if(bits0[i0]){
                    X(qs[i0]);
                }
                set i0 = i0 + 1;
            }

            H(qs[i0]);
            for(i in i0+1..N-1){
                if(bits0[i] != bits1[i]){
                    CNOT(qs[i0], qs[i]);
                    if(bits0[i0] != bits0[i]){
                        X(qs[i]);
                    }
                }elif(bits0[i]){
                    X(qs[i]);
                }
            }

        }
    }
}