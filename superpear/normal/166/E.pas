const bigp=1000000007;
var e,i,n:longint;
begin
  readln(n);
  e:=0;
  for i:=2 to n do
    if i mod 2=0 then e:=(int64(e)*3+3) mod bigp else e:=(int64(e)*3-3+bigp) mod bigp;
  writeln(e);
end.