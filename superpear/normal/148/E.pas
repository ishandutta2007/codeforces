var m,n,i,j,k,u,v,e,max:longint;
    a,b,f,sum:array[0..30000] of longint;
begin
  readln(n,m);
  for i:=1 to m do
    f[i]:=-maxlongint;
  f[0]:=0;
  for i:=1 to n do
    begin
      read(k);
      for j:=1 to k do read(a[j]);
      sum[0]:=0;
      for j:=1 to k do
        sum[j]:=sum[j-1]+a[j];
      fillchar(b,sizeof(b),0);
      for u:=0 to k do
        for v:=0 to k-u do
          begin
            e:=sum[u]+sum[k]-sum[k-v];
            if e>b[u+v] then b[u+v]:=e;
          end;
      for u:=m downto 1 do
        for v:=1 to k do
          if u>=v then
            if f[u-v]+b[v]>f[u] then
              f[u]:=f[u-v]+b[v];
    end;
  max:=0;
  for i:=1 to m do
    if f[i]>max then max:=f[i];
  writeln(max);
end.