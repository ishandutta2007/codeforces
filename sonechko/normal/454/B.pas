var n,m,i,j,k,l,r:longint;
    a:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    for i:=2 to n do
     if a[i]<a[i-1] then l:=i-1;
     if l=0 then begin writeln(0); halt; end;
    for I:=2 to l do
     if a[i]<a[i-1] then begin writeln('-1'); halt; end;
    for i:=l+2 to n do
     if a[i]<a[i-1] then begin writeln('-1'); halt; end;
    if (a[n]<=a[1])
    then writeln(n-l) else writeln('-1');
  end.