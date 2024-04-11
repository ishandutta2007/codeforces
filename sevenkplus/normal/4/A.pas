program A;
var n:longint;
begin
  readln(n);
  if (n>=4) and not odd(n) then writeln('YES') else writeln('NO');
end.