var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i],b[i]);
    for i:=1 to n do
     for j:=i+1 to n do
      if (a[i]+b[i]=a[j]) and (a[j]+b[j]=a[i]) then begin writeln('YES'); halt; end;
    writeln('NO');
  end.