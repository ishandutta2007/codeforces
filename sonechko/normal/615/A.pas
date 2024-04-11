var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100,1..100]of longint;
    b:array[1..100]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(k);
       for j:=1 to k do
        begin
          read(l);
          b[l]:=1;
        end;
     end;
    for i:=1 to m do
     if b[i]=0 then begin writeln('NO'); halt; end;
    writeln('YES');
  end.