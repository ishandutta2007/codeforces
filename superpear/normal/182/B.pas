var d,n,i,ans:longint;
    a:array[0..2000000] of longint;
begin
  readln(d);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  ans:=0;
  for i:=1 to n-1 do
    ans:=ans+d-a[i];
  writeln(ans);
end.