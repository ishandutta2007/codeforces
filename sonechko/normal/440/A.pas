var n,i,j:longint;
    a,b:Array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n-1 do
     read(a[i]);
    for i:=1 to n-1 do
     inc(b[a[i]]);
    for i:=1 to n do
     if b[i]=0 then begin writeln(i); halt; end;
  end.