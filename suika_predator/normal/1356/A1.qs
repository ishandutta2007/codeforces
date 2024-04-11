namespace Solution
{
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int
    {
        using(q=Qubit())
        {
            unitary(q);
            let ret=M(q);
            Reset(q);
            if(ret==One)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}