namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        // your code here
        using(t = Qubit[2]){
            H(t[0]);
            H(t[1]);
            
            for(i in 0..Length(qs)-1){
                for(j in 0..3){
                    if(bits[j][i]){
                        (ControlledOnInt(j, X))(t, qs[i]);
                    }
                }
            }

            for(j in 0..3){
                if(j % 2 == 1){
                    (ControlledOnBitString(bits[j], X))(qs, t[0]);
                }
                if(j / 2 == 1){
                    (ControlledOnBitString(bits[j], X))(qs, t[1]);
                }
            }
        }
    }
}