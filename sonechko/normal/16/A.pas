var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100,1..100]of char;
    ch,h:char;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       for j:=1 to m do
        read(a[i,j]);
       readln;
     end;
    for j:=1 to m do
     if j=1 then ch:=a[1,1] else
     if ch<>a[1,j] then begin writeln('NO'); halt; end;
    for i:=2 to n do
     begin
       h:=a[i,1];
       if ch=h then begin writeln('NO'); halt; end;
       for j:=2 to m do
        if a[i,j]<>h then begin writeln('NO'); halt; end;
       ch:=h;
     end;
    writeln('YES');
  end.