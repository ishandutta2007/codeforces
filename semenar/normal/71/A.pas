program Slovo;
var n, i: integer;
tmp: string;
slova: array [1..100] of string;
begin
readln(n);
for i:=1 to n do
  begin
  readln(slova[i]);
  if length(slova[i]) > 10 then 
    begin
    Str(length(slova[i])-2,tmp);
    slova[i] := slova[i][1]+tmp+slova[i][length(slova[i])];
    end;
  end;
for i:=1 to n do
  writeln(slova[i]);
end.