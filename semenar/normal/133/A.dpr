program HQ;
var i: integer;
prog, printed: string;
begin
readln(prog);
printed := 'NO';
for i:=1 to length(prog) do
  if (prog[i] = 'H') or (prog[i] = 'Q') or (prog[i] = '9') then printed := 'YES';
writeln(printed);
end.