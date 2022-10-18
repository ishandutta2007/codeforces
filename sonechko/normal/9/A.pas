var max,n,m:longint;
  begin
    read(n,m);
    if n>m then max:=n else max:=m;
    if max=1 then writeln('1/1') else
    if max=2 then writeln('5/6') else
    if max=3 then writeln('2/3') else
    if max=4 then writeln('1/2') else
    if max=5 then writeln('1/3') else writeln('1/6');
  end.