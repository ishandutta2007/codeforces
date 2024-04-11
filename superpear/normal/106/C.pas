var m,n,i,ai,bi,ci,di,j,k,max:longint;
    a,b,c,f:array[0..10000] of longint;
begin
  readln(n,m,a[0],b[0]);
  c[0]:=1000;
  for i:=1 to m do
    begin
      readln(ai,bi,ci,di);
      a[i]:=ci;
      b[i]:=di;
      c[i]:=ai div bi;
    end;
  for i:=0 to 1000 do f[i]:=-maxlongint;
  f[0]:=0;
  for i:=0 to m do
    for j:=1 to c[i] do
      for k:=n downto a[i] do
        if f[k-a[i]]+b[i]>f[k] then f[k]:=f[k-a[i]]+b[i];
  max:=0;
  for i:=1 to n do if f[i]>max then max:=f[i];
  writeln(max);
end.