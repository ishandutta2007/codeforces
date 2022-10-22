namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        // your code here

        let N = Length(register!);
        for(i in 0..N-2){
            Controlled X(register![0..N-2-i], register![N-1-i]);
        }
        X(register![0]);
    }
}