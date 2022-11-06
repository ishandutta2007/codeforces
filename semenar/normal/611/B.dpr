program Limak2;
var ystart, yend, year: int64;
stepeni: array [0..60] of int64;
sum, i, k: integer;
begin
readln(ystart,yend);
stepeni[0]:=0;
sum:=0;
for i:=1 to 60 do
  stepeni[i]:=stepeni[i-1]*2+1;
for i:=2 to 60 do
  for k:=0 to i-2 do
    begin
    year := stepeni[i]-stepeni[k]-1;
    if (year >= ystart) and (year <= yend) then sum := sum+1;
    end;
writeln(sum);
end.