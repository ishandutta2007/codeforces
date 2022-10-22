namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable angle = 0.0;
        mutable ok = false;
        let pi = 3.141592953589793;
        let eps = 0.01;
        mutable ans = -1;
        using(q = Qubit()){
            repeat{
                unitary(q);
                set angle = angle + theta / 2.0;
                if(angle > 2.0 * pi){
                    set angle = angle - 2.0 * pi;
                }
            }
            until(-eps < angle - pi / 2.0 and angle - pi / 2.0 < eps);

            if(M(q) == Zero){
                set ans = 0;
            }else{
                set ans = 1;
            }
            ResetAll([q]);
        }
        return ans;
    }
}