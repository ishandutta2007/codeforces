namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : () {
    body {
      let n = Length(qs);
      mutable first = -1;
      for (i in 0 .. n - 1) {
        if (bits0[i] != bits1[i]) {
          set first = i;
        }
      }
      H(qs[first]);
      for (i in 0 .. n - 1) {
        if (bits0[i] == bits1[i]) {
          if (bits0[i]) {
            X(qs[i]);
          }
        } elif (i != first) {
          CNOT(qs[first], qs[i]);
          if (bits0[i] != bits0[first]) {
            X(qs[i]);
          }
        }
      }
    }
  }
}