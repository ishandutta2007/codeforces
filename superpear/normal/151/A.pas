var n,k,l,c,d,p,nl,np,a1,a2,b1,b2,b3,e:longint;
begin
  readln(n,k,l,c,d,p,nl,np);
  a1:=k*l;
  a2:=c*d;
  b1:=a1 div nl;
  b2:=a2;
  b3:=p div np;
  e:=b1;
  if b2<e then e:=b2;
  if b3<e then e:=b3;
  writeln(e div n);
end.