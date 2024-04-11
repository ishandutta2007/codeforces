var a:array[1..100] of longint;
    n,i,x,y,s:longint;
begin
  readln(n);
  for i:=1 to n-1 do read(a[i]);
  readln(x,y);
  s:=0;
  for i:=x to y-1 do inc(s,a[i]);
  writeln(s);
end.