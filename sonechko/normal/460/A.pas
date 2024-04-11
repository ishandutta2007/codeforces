VAR i,n,m,k:longint;
  begin
    read(n,m);
    i:=1;
    while i<=n do
     begin
       if i mod m=0 then begin inc(n); inc(i); end else inc(i);
     end;
    writeln(n);
  end.