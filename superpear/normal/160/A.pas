var n,i,s,j,ans:longint;
    a,f:array[0..50000] of longint;
begin
  readln(n);
  filldword(f,sizeof(f) div 4,maxlongint);
  f[0]:=0;
  s:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      s:=s+a[i];
    end;
  for i:=1 to n do
    for j:=s downto a[i] do
      if f[j-a[i]]<>maxlongint then
        if f[j-a[i]]+1<f[j] then f[j]:=f[j-a[i]]+1;
  ans:=maxlongint;
  for i:=(s div 2+1) to s do
    if f[i]<ans then ans:=f[i];
  writeln(ans);
end.