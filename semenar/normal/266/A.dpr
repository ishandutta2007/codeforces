program Stones;
var n, sum, i: integer;
stone, last_stone: char;
begin
readln(n);
sum := 0;
last_stone := 'D';
for i:=1 to n do
  begin
  read(stone);
  if stone = last_stone then sum := sum+1;
  last_stone := stone;
  end;
writeln(sum);
end.