namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable res = 0;
        let low = MinD(theta, PI()-theta);
        mutable cur = 0.0;
        mutable ntimes = 0.0;
        
        
        using (qs = (Qubit[1])) {
            // mutable numone = 0;
            for (test in 0 .. 40) {
                // unitary(qs[0]);
                set cur = 0.0;
                repeat {
                    unitary(qs[0]);
                    set cur = cur + low;
                } until (cur > PI()/4.0);

                if (M(qs[0]) == One) {
                    set res = 1;
                    Reset(qs[0]);
                    // break;
                }
                // Reset(qs[0]);
            }
        }
        return res;
    }
}