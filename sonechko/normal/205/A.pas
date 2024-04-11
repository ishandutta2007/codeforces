var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    l:=1;
    for i:=1 to n do
     if a[i]<a[l] then l:=i;
    for i:=1 to n do
     if (a[i]=a[l]) and (i<>l) then begin writeln('Still Rozdil'); halt; end;
    writeln(l);
  end.