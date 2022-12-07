const
  maxn = 4444;

var
  us:array[0..maxn, 0..maxn] of byte;
  ma:array[0..maxn] of record
    fi, se:longint;
  end;
  xdd,was,pred,cost,u,sg,ind,f,a:array[0..maxn] of longint;
  l,r:array[0..maxn] of int64;
  xd,oo,better,max,mi,ci,ri,segs,last,ww,i,j,k,n:longint;
  min:int64;

procedure qs(const l, r:longint);
var
  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r) shr 1];
  repeat
    while x>a[i] do inc(i);
    while x<a[j] do dec(j);
    if j<i then break;
    y:=a[i]; a[i]:=a[j]; a[j]:=y;
    inc(i); dec(j);
  until j<i;
  if l<j then qs(l, j);
  if i<r then qs(i, r);
end;

procedure qs2(const le, ri:longint);
var
  i,j,x,y,t:longint;
begin
  i:=le; j:=ri;
  x:=l[(le+ri) shr 1];
  y:=r[(le+ri) shr 1];
  repeat
    while (x>l[i])or((x = l[i])and(y>r[i])) do inc(i);
    while (x<l[j])or((x = l[j])and(y<r[j])) do dec(j);
    if j<i then break;
    t:=l[i]; l[i]:=l[j]; l[j]:=t;
    t:=r[i]; r[i]:=r[j]; r[j]:=t;
    t:=ind[i]; ind[i]:=ind[j]; ind[j]:=t;
    inc(i); dec(j);
  until j<i;
  if le<j then qs2(le, j);
  if i<ri then qs2(i, ri);
end;

procedure get_indexes;
begin
  qs(1, n+n);
  ww:=1;
  for i:=2 to n+n do if a[i] <> a[ww] then
  begin
    inc(ww);
    a[ww]:=a[i];
  end;
  for i:=1 to n do
  begin
    for j:=1 to ww do if l[i] = a[j] then
    begin
      l[i]:=j;
      break;
    end;
    for j:=1 to ww do if r[i] = a[j] then
    begin
      r[i]:=j;
      break;
    end;
  end;
end;

function findmax(const x:longint):longint;
var
  i:longint;
begin
  for i:=last+1 to x do if ma[i].fi<ma[i-1].fi then ma[i]:=ma[i-1];
  if last<x then last:=x;
  findmax:=ma[x].fi;
  better:=ma[x].se;
end;

procedure modify(const j, pf, ps:longint);
var
  i:longint;
begin
  if ma[j].fi>pf then exit;
  ma[j].fi:=pf;
  ma[j].se:=ps;
{  for i:=last+1 to j do if ma[i].fi<ma[i-1].fi then ma[i]:=ma[i-1];
  if last<j then last:=j;}
end;

procedure process(const wh:longint);
var
  q,i:longint;
begin
  fillchar(ma, sizeof(ma), 0);
  fillchar(pred, sizeof(pred), 0);
  segs:=0; last:=0;
  for i:=1 to n do if (l[wh]<=l[i])and(r[wh]>=r[i])and(i<>wh) then
  begin
    inc(segs);
    sg[segs]:=i;
    cost[segs]:=f[i];
  end;
  for i:=1 to segs do
  begin
    q:=findmax(l[sg[i]])+cost[i];
    modify(r[sg[i]], q, i);
    pred[i]:=better;
  end;
  for i:=1 to n+n do if ma[i].fi>f[wh] then
  begin
    f[wh]:=ma[i].fi;
    oo:=ma[i].se;
  end;
  while oo>0 do
  begin
    us[ind[wh], ind[sg[oo]]]:=1;
    oo:=pred[oo];
  end;
  us[ind[wh], ind[wh]]:=1;
  inc(f[wh]);
end;

procedure restore(const k:longint);
var
  i:longint;
begin
  if was[k] = 1 then exit;
  was[k]:=1;
  for i:=1 to n do if us[k, i] = 1 then restore(i);
end;

begin
{  assign(input, 'input.txt');
  reset(input);
  assign(output, 'output.txt');
  rewrite(output);}
  read(n);
  for i:=1 to n do
  begin
    read(ci, ri);
    l[i]:=ci-ri;
    r[i]:=ci+ri;
    a[i]:=l[i];
    a[n+i]:=r[i];
    ind[i]:=i;
  end;
  inc(n);
  l[n]:=-2000000100;
  r[n]:=+2000000100;
  ind[n]:=n;
  a[n+n-1]:=l[n];
  a[n+n]:=r[n];
  get_indexes;
  qs2(1, n);
  for i:=1 to n do
  begin
    min:=int64(maxlongint)+int64(maxlongint);
    mi:=-11;
    for j:=1 to n do if (min>r[j]-l[j])and(u[j] = 0) then
    begin
      min:=r[j]-l[j];
      mi:=j;
    end;
    u[mi]:=1;
    process(mi);
  end;
  max:=0;
  for i:=1 to n do if f[i]>max then
  begin
    max:=f[i];
    mi:=i;
  end;
  xd:=0;
  restore(ind[mi]);
  writeln(max-1);
  for i:=1 to n-1 do if was[i] = 1 then
  begin
    inc(xd);
    xdd[xd]:=i;
  end;
  for i:=1 to xd-1 do write(xdd[i], ' ');
  writeln(xdd[xd]);
  close(output);
end.