var n,m,i,j,k,l,r:Longint;
    a:array[1..100]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     if (a[i]>=a[m]) and (a[i]>0) then inc(l);
    writeln(l);
  end.