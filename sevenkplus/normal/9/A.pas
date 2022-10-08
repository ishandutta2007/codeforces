program A_;
var a,b:longint;
begin
  readln(a,b);
  if a<b then a:=b;
  if a=1 then writeln('1/1') else
  if a=2 then writeln('5/6') else
  if a=3 then writeln('2/3') else
  if a=4 then writeln('1/2') else
  if a=5 then writeln('1/3') else writeln('1/6');
end.