program EasyFunction;
var n, res: int64;
begin
readln(n);
res := (n+1) div 2;
if n mod 2 = 1 then res := -res;
writeln(res);
end.