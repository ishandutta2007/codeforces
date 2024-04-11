program Caps;
var capsed, i: integer;
cstr, newstr: string;
begin
readln(cstr);
capsed := 1;
for i:=2 to length(cstr) do
  if ord(cstr[i]) > 96 then capsed := 0;
newstr := cstr;
if capsed = 1 then for i:=1 to length(cstr) do
  if ord(cstr[i]) > 96 then newstr[i] := chr(ord(cstr[i])-32) else newstr[i] := chr(ord(cstr[i])+32);
writeln(newstr);
end.