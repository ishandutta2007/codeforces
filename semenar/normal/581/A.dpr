program Socks;
var a, b: integer;

function min(a,b:integer):integer;
begin
if a<b then min:=a else min:=b;
end;

begin
readln(a,b);
writeln(min(a,b),' ',((a+b-2*min(a,b)) div 2));
end.