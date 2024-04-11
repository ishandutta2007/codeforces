namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation Set (q: Qubit, des: Result) : Unit {
        if(des != M(q)){ X(q); }
    }

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        // your code here
        let arr = register!;

        for(i in 0..Length(arr)-1){
            X(arr[i]);
        }

        for(i in 0..Length(arr)-2){
            let a = Length(arr)-1-i;
            Controlled X(arr[0..(a-1)], arr[a]);
        }
        X(arr[0]);

        for(i in 0..Length(arr)-1){
            X(arr[i]);
        }
    }
}