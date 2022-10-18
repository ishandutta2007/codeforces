var p,n,m,i,j:longint;
    a,b,x:array[1..1000000]of longint;
  begin
    read(n,m,p);
    for i:=1 to m do
     begin
     read(a[i]);
     x[a[i]]:=1;
     end;
    for i:=1 to p do   begin
     read(b[i]);            x[b[i]]:=2; end;
    for i:=1 to n do
     write(x[i],' ');
  end.