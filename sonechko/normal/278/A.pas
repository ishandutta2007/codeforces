uses math;
var n,m,i,j,k,l,r:longint;
    a:array[1..10000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    read(l,r);
    if l>r then begin k:=l;l:=r;r:=k;end;
    for i:=l to r-1 do
     m:=m+a[i];
    k:=0;
    for i:=r to n do
     k:=k+a[i];
    for i:=1 to l-1 do
     k:=k+a[i];
    writeln(min(m,k));
  end.