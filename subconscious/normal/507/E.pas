type
  u=record
    x,y,z,t:longint;
  end;
var
  a,d:Array[1..200001] of u;
  b,c,e,f,g:array[1..100001] of longint;
  n,m,i,j,k,l,r,p:longint;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(a[i].x,a[i].y,a[i].z);a[i].z:=a[i].z xor 1;
    inc(b[a[i].x]);inc(b[a[i].y]);
    if a[i].z=0 then p:=p+1;
  end;
  for i:=2 to n+1 do b[i]:=b[i]+b[i-1];
  for i:=1 to m do
  begin
    d[b[a[i].x]]:=a[i];d[b[a[i].x]].t:=b[a[i].y];
    dec(b[a[i].x]);
    k:=a[i].x;a[i].x:=a[i].y;a[i].y:=k;
    d[b[a[i].x]]:=a[i];d[b[a[i].x]].t:=b[a[i].y]+1;
    dec(b[a[i].x]);
  end;
  fillchar(e,sizeof(e),127);e[1]:=0;
  l:=1;r:=1;c[1]:=1;
  repeat
    for i:=b[c[l]]+1 to b[c[l]+1] do
    if (d[i].y<>1) and (g[d[i].y]=0) then
    begin
      g[d[i].y]:=g[c[l]]+1;
      r:=r+1;
      c[r]:=d[i].y;
      e[c[r]]:=e[c[l]]+d[i].z;
      f[c[r]]:=i;
    end else if (g[d[i].y]=g[c[l]]+1) and (e[d[i].y]>e[c[l]]+d[i].z) then
    begin
      e[d[i].y]:=e[c[l]]+d[i].z;
      f[d[i].y]:=i;
    end;
    l:=l+1;
  until c[l]=n;

  writeln(p-g[n]+2*e[n]);
  k:=n;
  while k<>1 do
  begin
    if d[f[k]].z=1 then writeln(d[f[k]].x,' ',d[f[k]].y,' ',d[f[k]].z) else
    begin d[f[k]].z:=1; end; d[d[f[k]].t].z:=1;
    k:=d[f[k]].x;
  end;
  for i:=1 to 2*m do if d[i].z=0 then begin writeln(d[i].x,' ',d[i].y,' ',d[i].z); d[d[i].t].z:=1; end;

end.