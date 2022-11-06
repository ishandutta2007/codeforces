program Jews;
var n, m, a, b, sum: integer;

function min(a,b:integer):integer;
begin
if a>b then min:=b else min:=a;
end;

begin
readln(n,m,a,b);
if (b/m < a) then sum:=min(b*(n div m)+a*(n mod m),b*((n div m)+1)) else sum:=a*n;
writeln(sum);
end.