program OhMyKeyboard;
var lr, i: integer;
tmp, keyboard, msg: string;
begin
keyboard:='qwertyuiopasdfghjkl;zxcvbnm,./';
readln(tmp);
if (tmp='L') then lr:=1 else lr:=-1;
readln(msg);
for i:=1 to length(msg) do
  msg[i]:=keyboard[pos(msg[i],keyboard)+lr];
writeln(msg);
end.