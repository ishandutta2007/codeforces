program DoTheMath;
var a, b, c: integer;

function max(a, b: integer): integer;
begin
if a>b then max:=a else max:=b;
end;

begin
readln(a);
readln(b);
readln(c);
writeln(max(max(max(a*b*c,a*(b+c)),max((a+b)*c,a+b*c)),max(a*b+c,a+b+c)));
end.