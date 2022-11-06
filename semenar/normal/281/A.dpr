program Capitalization;
var cap: string;
begin
readln(cap);
if ord(cap[1]) > 96 then cap[1] := chr(ord(cap[1])-32);
writeln(cap);
end.