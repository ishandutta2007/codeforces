program A;
var n,p1,p2,p3,t1,t2,l,r,r1,i,s:longint;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  readln(n,p1,p2,p3,t1,t2);s:=0;
  for i:=1 to n do
    begin
      readln(l,r);
      inc(s,p1*(r-l));
      if i<>1 then
      if l-r1<=t1 then inc(s,p1*(l-r1)) else
      if l-r1<=t1+t2 then inc(s,p1*t1+p2*(l-r1-t1)) else
      inc(s,p1*t1+p2*t2+p3*(l-r1-t1-t2));
      r1:=r;
    end;
  writeln(s);
//  close(input);close(output);
end.