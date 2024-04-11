program Dreamoon;
var n, m: integer;
begin
readln(n,m);
if n<m then writeln(-1) else writeln(((((n+1) div 2)+m-1) div m)*m);
end.