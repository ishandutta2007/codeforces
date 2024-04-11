namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation SetOneBit (q : Qubit, need : Result) : () {
    body {
      if (M(q) != need) {
        X(q);
      }
    }
  }

  operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool {
    body {
      mutable ans = true;
      using (qs = Qubit[N + 1]) {
        for (i in 0 .. N - 1) {
          SetOneBit(qs[i], Zero);
        }
        SetOneBit(qs[N], One);
        for (i in 0 .. N) {
          H(qs[i]);
        }
        Uf(qs[0 .. N - 1], qs[N]);
        for (i in 0 .. N) {
          H(qs[i]);
        }
        for (i in 0 .. N - 1) {
          if (M(qs[i]) == One) {
            set ans = false;
          }
        }
        for (i in 0 .. N) {
          SetOneBit(qs[i], Zero);
        }
      }
      return ans;
    }
  }
}