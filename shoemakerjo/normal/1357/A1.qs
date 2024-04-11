namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable res = 0;
        using ((a, b) = (Qubit(), Qubit())) {
            X(a);
            unitary([a, b]);
            if (M(b) == One) {
                set res = 0;
            }
            else {
                set res = 1;
            }
            Reset(a);
            Reset(b);
            
        }
        return res;
    }
}