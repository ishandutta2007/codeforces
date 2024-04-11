namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return ([
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ],
        ([3.135718843750002], 0.00035000000000001696));
    }
}