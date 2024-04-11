var a:array[1..10000]of longint;
    i,j,k,l,r,n,m:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       a[l]:=i;
     end;
    for i:=1 to n do
     write(a[i],' ');
    writeln;

  end.