
program cf200_3;

var
    a,b,s:int64;

function f(x,y:int64):int64;
begin
  if y=1 then f:=x else
  if x>y then f:=x div y+f(x mod y,y)
  else f:=f(y,x);
end;

begin
  readln(a,b);
  writeln(f(a,b));
end.