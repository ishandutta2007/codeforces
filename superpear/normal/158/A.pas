var n,k,i,e,s:longint;
    a:array[0..10000] of longint;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  e:=k;
  while (e<n) and (a[e]=a[e+1]) do e:=e+1;
  s:=0;
  for i:=1 to e do
    if a[i]>0 then inc(s);
  writeln(s);
end.