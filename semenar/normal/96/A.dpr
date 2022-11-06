program Football;
var big, i: integer;
position, yes: string;
now: char;
begin
readln(position);
big := 1;
yes := 'NO';
now := position[1];
for i:=2 to length(position) do
  if now = position[i] then 
    begin
    big := big+1;
    if big >= 7 then yes := 'YES';
    end
   else
    begin
    big := 1;
    now := position[i];
    end;
writeln(yes);
end.