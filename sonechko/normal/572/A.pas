var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100000]of longint;
  begin
    read(n,m,l,r);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to m do
     read(b[i]);
    if a[l]<b[m-r+1] then writeln('YES') else writeln('NO');
  end.