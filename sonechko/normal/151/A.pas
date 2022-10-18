uses math;
var n,k,l,c,d,p,nl,np,r1,r2,r3:longint;
  begin
    read(N,k,l,c,d,p,nl,np);
    r1:=(k*l)div nl;
    r2:=(c*d);
    r3:=p div np;
    writeln(min(r1,min(r2,r3)) div n);
  end.