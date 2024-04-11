namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {  
          mutable pos=0;
          let n=Length(qs);
          for(i in 0..n-1){
            if(bits0[i]!=bits1[i]){
              set pos=i;
            }
          }
          H(qs[pos]);
          for(i in 0..n-1){
            if(i!=pos){
              if(bits0[i]!=bits1[i]){
                CNOT(qs[pos],qs[i]);
                if(bits0[i]!=bits0[pos]){
                  X(qs[i]);
                }
              }
              else{
                if(bits0[i]){
                  X(qs[i]);
                }
              }
            }
          }
        }
    }
}