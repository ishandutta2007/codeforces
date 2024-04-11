var n,e:longint;
begin
  readln(n);
  e:=1;
  while n>5*e do
    begin
      n:=n-5*e;
      e:=e*2;
    end;
  n:=(n-1) div e+1;
  if n=1 then writeln('Sheldon');
  if n=2 then writeln('Leonard');
  if n=3 then writeln('Penny');
  if n=4 then writeln('Rajesh');
  if n=5 then writeln('Howard');
end.