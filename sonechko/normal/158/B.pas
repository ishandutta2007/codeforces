var n,m,i,j,k,l,r:longint;
    a:array[1..5]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       inc(a[l]);
     end;
    if a[1]>a[3] then a[2]:=a[2]+((a[1]-a[3]+1)div 2);
    writeln(a[4]+(a[2]+1) div 2+a[3]);
  end.