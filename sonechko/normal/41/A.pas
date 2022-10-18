var s,t,d:ansistring;
    i:longint;
  begin
    readln(s);
    readlN(t);
    for i:=1 to length(t) do
     d:=t[i]+d;
    if s=d then writeln('YES') else writeln('NO');
  end.