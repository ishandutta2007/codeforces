// This file is submitted by the participant
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    // The operation that the participant has to implement
    // Has to return three things: 
    //  1) the feature engineering to perform (as an index in the array of feature engineering functions and an array of parameters to be used with it)
    //  2) circuit structure (as an array of ControlledRotation)
    //  3) and training results (circuit parameters + bias)
    //
    // The features engineering is built-in and cannot be tweaked by the participant's solution, only chosen from the list 
    // (see quantum-checker.qs for the list of available feature engineering functions)
    //
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [1.0]), 
                [ControlledRotation((1, [0]), PauliY, 1),
                ControlledRotation((0, new Int[0]), PauliY, 0),
                ControlledRotation((1, new Int[0]), PauliY, 2)],
                ([-3.9690000000000065, 3.0, 0.030999999999993477], 0.10852399067349511));
    }


}