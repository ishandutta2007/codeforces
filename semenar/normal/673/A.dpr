program Round3div2;
var n, i, a, match: integer;
begin
  readln(n);
  match:=0;
  for i:=1 to n do
    begin
    read(a);
    if (a <= match+15) then match:=a;
    end;
  match:=match+15;
  if (match>90) then match:=90;
  writeln(match);
end.