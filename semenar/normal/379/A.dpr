program Romantic;
var a, b, sum: integer;
begin
readln(a, b);
sum:=0;
sum:=(a*b) div (b-1);
if ((a*b) mod (b-1)) = 0 then sum:=sum-1;
writeln(sum);
end.