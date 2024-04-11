program Happiness2;
var i, cur: integer;
number: string;
begin
readln(number);
cur:=0;
for i:=1 to length(number) do
  if (number[i]='4') or (number[i]='7') then cur:=cur+1;
if (cur=4) or (cur=7) then writeln('YES') else writeln('NO');
end.