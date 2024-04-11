program LuckyNumbers;
var n, t, i: integer;
ss: string;
begin
readln(n,t);
if (t=10) and (n=1) then writeln(-1) else
  begin
  if t=10 then t:=1;
  ss:='';
  for i:=1 to n-1 do
    ss:=ss+'0';
  writeln(t,ss);
  end;
end.