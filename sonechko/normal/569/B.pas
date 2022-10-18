var a,b,c,d:array[1..100000]of longint;
    i,j,n,m,k,ans,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(a[i]);
       if (b[a[i]]=0) and (a[i]<=n) then begin c[i]:=1; b[a[i]]:=1; end;
     end;
    for i:=1 to n do
     if b[i]=0 then begin inc(m); d[m]:=i; end;
    for i:=1 to n do
     if c[i]=0 then begin a[i]:=d[m]; dec(m); end;
    for i:=1 to n do
     write(a[i],' ');
    writeln;
  end.