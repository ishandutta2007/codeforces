program ThisIsMagic;
var n, m1, m2: integer;
begin
readln(n);
if (n>0) then writeln(n)
else
  begin
  m1:=n div 10;
  m2:=((n div 10) div 10)*10+(n mod 10);
  if m1>m2 then writeln(m1) else writeln(m2);
  end;
end.