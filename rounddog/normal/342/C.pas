
program cf199_3;

var
    r,h,t:longint;

begin
  readln(r,h);
  r:=2*r;
  h:=2*h;
  if (h+r-((h+r div 2) div r)*r)/r>sqrt(3)/2 then t:=1 else t:=0;
  t:=((h+r div 2) div r)*2+t;
  writeln(t);
end.