var n,m,i,j,k,l,r:longint;
    a:array[1..100000]of string;
  begin
    readln(n);
    for i:=1 to n do
     readln(a[i]);
    k:=0;
    for i:=2 to n do
     if a[i]<>a[i-1] then inc(k);
    writeln(k+1);
  end.