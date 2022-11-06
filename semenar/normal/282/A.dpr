program Bit;
var n, i, x: integer;
command: string;
begin
readln(n);
x := 0;
for i:=1 to n do
  begin
  readln(command);
  if pos('+',command) > 0 then x:=x+1 else x:=x-1;
  end;
writeln(x);
end.