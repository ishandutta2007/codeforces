var n,m,i,j,k,ans,l,r:longint;
    a:array[0..10,0..10]of longint;
  begin
    read(n);
    a[1,1]:=1;
    for i:=1 to n do
     for j:=1 to n do
      if (i<>1) or (j<>1) then a[i,j]:=a[i-1,j]+a[i,j-1];
    writeln(a[n,n]);
  end.