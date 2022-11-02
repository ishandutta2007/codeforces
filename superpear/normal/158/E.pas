var n,k,i,j,e,ans:longint;
    t,d:array[0..10000] of longint;
    f:array[0..5000,0..5000] of longint;
begin
  readln(n,k);
  for i:=1 to n do
    readln(t[i],d[i]);
  t[n+1]:=86401;
  ans:=0;
  filldword(f,sizeof(f) div 4,maxlongint);
  f[0,0]:=1;
  for i:=0 to n do
    for j:=0 to k do
      if f[i,j]<>maxlongint then
        begin
          e:=t[i+1];
          if e>86401 then e:=86401;
          if e-f[i,j]>ans then ans:=e-f[i,j];
          if f[i,j]<f[i+1,j+1] then f[i+1,j+1]:=f[i,j];
          e:=f[i,j];
          if t[i+1]>e then e:=t[i+1];
          e:=e+d[i+1];
          if e<f[i+1,j] then f[i+1,j]:=e;
        end;
  writeln(ans);
end.