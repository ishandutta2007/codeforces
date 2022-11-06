program Strokes;
var stroke, ns, aoyeiu: string;
i: integer;
begin
aoyeiu := 'aoyeiu';
readln(stroke);
ns := '';
for i:=1 to length(stroke) do
  begin
  if (ord(stroke[i]) < 97) then stroke[i] := chr(ord(stroke[i])+32);
  if (pos(stroke[i],aoyeiu) = 0)
    then ns := ns+'.'+stroke[i];
  end;
writeln(ns);
end.