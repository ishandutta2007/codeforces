var n,m,i,j,k,l,r:longint;
    a:array[1..1000]of longint;
  begin
    read(n,m);
    k:=1;
    for i:=1 to n do
     begin
       read(a[i]);
     end;
    l:=0;
    for I:=1 to n do
     begin
       if l+a[i]<=m then l:=l+a[i] else begin inc(k); l:=a[i]; end;
     end;
    writeln(k);
  end.