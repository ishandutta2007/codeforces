var n,m,i,j,k,l,r:longint;
    a:array[1..1000]of longint;
  begin
    read(n);
    for i:=2 to n do
     read(a[i]);
    read(l,r);
    k:=0;
    for i:=l+1 to r do
     k:=k+a[i];
    writeln(k);
  end.