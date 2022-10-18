var n,m,i,j,k,l,r:longint;
    a,b:array[0..3005]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     read(a[i]);
    for j:=1 to m do
     read(b[j]);
    for i:=1 to n do
     begin
       k:=0;
       for j:=1 to m do
        if a[i]<=b[j] then begin k:=j; break; end;
       if b[k]>=a[i] then begin a[i]:=-1; b[k]:=-1; end;
     end;
    k:=0;
    for i:=1 to n do
     if a[i]<>-1 then inc(k);
    writeln(k);
  end.