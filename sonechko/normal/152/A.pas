var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100,1..100]of char;
    b:array[1..100]of longint;
    h:char;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       for j:=1 to m do
        read(a[i,j]);
       readln;
     end;
    for i:=1 to m do
     begin
       h:='0';
       for j:=1 to n do
        if a[j,i]>h then h:=a[j,i];
       for j:=1 to n do
        if a[j,i]=h then b[j]:=1;
     end;
    for i:=1 to n do
     if b[i]=1 then inc(ans);
    writeln(ans);
  end.