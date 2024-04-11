var a:array[0..100] of int64;
    s,i:longint;
begin
  readln(a[0],a[1],s);
  for i:=2 to s do
    a[i]:=a[i-1]+a[i-2];
  writeln(a[s]);
end.