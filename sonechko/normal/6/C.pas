var n,m,i,j,k,t,l,r,t1,t2,k1,k2:longint;
    a:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    l:=1;
    r:=n;
    t1:=0;
    t2:=0;
    k1:=0;
    k2:=0;
    while l<=r do
     if t1+a[l]<=t2+a[r] then
      begin
        t1:=t1+a[l];
        inc(l);
        inc(k1);
      end else
      begin
        t2:=t2+a[r];
        dec(r);
        inc(k2);
      end;
    writeln(k1,' ',k2);
  end.