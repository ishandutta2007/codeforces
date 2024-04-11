var n,m,i,j,k,l,r:longint;
    a:array[1..50000]of longint;
    b:array[1..50000]of boolean;
  begin
    read(n,m);
    for i:=1 to n-1 do
     read(a[i]);
    l:=0;
    i:=1;
    while l<>100000 do
     begin
       if i=m then begin writeln('YES'); halt; end;
       if b[i] then begin writeln('NO'); halt; end;
       b[i]:=true;
       i:=i+a[i];
     end;
  end.