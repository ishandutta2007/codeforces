namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        // your code here
        let num = p % 4;
        for(i in 0..num-1){
            Microsoft.Quantum.Canon.QFTLE(inputRegister);
        }
    }
}