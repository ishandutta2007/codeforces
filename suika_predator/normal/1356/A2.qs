namespace Solution
{
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int
    {
        using(q=Qubit())
        {
            H(q);
            unitary(q);
            H(q);
            let ret=M(q);
            Reset(q);
            return ret==One?1|0;
        }
    }
}