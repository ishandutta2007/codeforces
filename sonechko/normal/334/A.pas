var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    l:=1;
    r:=n*n;
    k:=n div 2;
    for i:=1 to n do
     begin
       j:=1;
       while j<=k do
        begin
          write(l,' ');
          inc(l);
          inc(j);
        end;
       j:=1;
       while j<=k do
        begin
          write(r,' ');
          dec(r);
          inc(j);
        end;
       writeln;
     end;
  end.