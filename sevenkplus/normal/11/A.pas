program A;
var n,d,i,p1,p,x:longint;
    s:int64;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  readln(n,d);s:=0;p1:=0;
  for i:=1 to n do
    begin
      read(p);
      if p>p1 then x:=0 else x:=(p1-p) div d+1;
      inc(s,x);p1:=p+x*d;
    end;
  writeln(s);
//  close(input);close(output);
end.