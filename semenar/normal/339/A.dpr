program Mathematics;
var i: integer;
primer, np: string;
num: array [1..3] of integer;
begin
readln(primer);
for i:=1 to 3 do
  num[i] := 0;
i := 1;
while length(primer) >= i do
  begin
  if primer[i] = '1' then num[1] := num[1]+1;
  if primer[i] = '2' then num[2] := num[2]+1;
  if primer[i] = '3' then num[3] := num[3]+1;
  i := i+2;
  end;
i := 1;
np := '';
while i <= num[1] do
  begin
  if i>1 then np:=np+'+';
  np := np+'1';
  i:=i+1;
  end;
while i <= num[1]+num[2] do
  begin
  if i>1 then np:=np+'+';
  np := np+'2';
  i:=i+1;
  end;
while i <= num[1]+num[2]+num[3] do
  begin
  if i>1 then np:=np+'+';
  np := np+'3';
  i:=i+1;
  end;
writeln(np);
end.