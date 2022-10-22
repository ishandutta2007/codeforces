namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return ([
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ],
        ([1.007010187499998], 0.24875000000000003));
    }
}