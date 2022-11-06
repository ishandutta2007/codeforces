program Rarity;
var sum, tmp, i: integer;
begin
sum:=0;
for i:=1 to 5 do
  begin
  read(tmp);
  sum:=sum+tmp;
  end;
if ((sum mod 5) > 0) or (sum = 0) then writeln(-1) else writeln(sum div 5);
end.