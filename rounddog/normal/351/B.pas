
program cf204_2;

var
    i,j,k,l,m,n:longint;
    a:array[0..3000] of longint;
    r:real;

begin
  readln(n);
  for i:= 1 to n do
    read(a[i]);
  readln;
  k:=0;
  for i:= 1 to n-1 do
    for j:= i+1 to n do
      if a[i]>a[j] then inc(k,2);
  if k mod 4<>0 then dec(k);
  r:=k;
  writeln(r:0:6);
end.