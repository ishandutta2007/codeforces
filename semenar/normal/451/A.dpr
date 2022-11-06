program Palochki;
var n, m: integer;

function min(a,b:integer): integer;
begin
if a>b then min:=b else min:=a;
end;

begin
readln(n, m);
if (min(n,m) mod 2) = 0 then writeln('Malvika') else writeln('Akshat');
end.