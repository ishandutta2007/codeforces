namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve(q : Qubit, sign : Int) : () {
    body {
      if (sign == -1) {
        X(q);
      }
      H(q);
    }
  }

  operation Test() : Bool {
    body {
      using (qb = Qubit[1]) {
        let x = qb[0];
        Solve(x, -1);
        ResetAll(qb);
      }
      return true;
    }
  }
}