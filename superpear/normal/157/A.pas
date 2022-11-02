var n,i,j,s,k,ans:longint;
    a:array[0..1000,0..1000] of longint;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
      begin
        s:=0;
        for k:=1 to n do
          s:=s+a[k,j]-a[i,k];
        if s>0 then inc(ans);
      end;
  writeln(ans);
end.