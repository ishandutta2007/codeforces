var a,b:array[1..100]of longint;
    i,j,k,n:longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i],b[i]);
    k:=0;
    for i:=1 to n do
     for j:=1 to n do
      if a[i]=b[j] then inc(k);
    writeln(k);
  end.