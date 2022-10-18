var n,m,k1,k2,l,r:int64;
    i,j:longint;
    a:array[1..200000+100]of longint;
  begin
    read(n);
    l:=maxlongint;
    r:=0;
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     begin
       if a[i]<L then l:=a[i];
       if a[i]>r then r:=a[i];
     end;
    for i:=1 to n do
     begin
       if a[i]=l then inc(k1);
       if a[i]=r then inc(k2);
     end;
    if l<>r then writeln(r-l,' ',k1*k2) else
    begin
     n:=n-1;
     writeln(r-l,' ',(n+1)*n div 2);
    end;
  end.