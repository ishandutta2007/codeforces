const pi=3.1415926535897932384626;

var n,r1,r2:longint;
    e:extended;

begin
  readln(n,r2,r1);
  if n=1 then
    begin
      if r2>=r1 then writeln('YES') else writeln('NO')
    end
  else
    if n=2 then
      begin
        if r2 div r1>=2 then writeln('YES') else writeln('NO')
      end
    else
      begin
        e:=(r2-r1)*sin(pi/n);
        if e>=r1 then writeln('YES') else writeln('NO');
      end;
end.