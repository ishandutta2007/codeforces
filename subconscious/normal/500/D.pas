var
  a,b,e:array[1..100001] of longint;
  c,d:array[1..200002,0..2] of longint;
  f:array[1..100001] of boolean;
  n,i,j,p,s:longint;
  ans1,ans2,k:int64;
function dfs(x:longint):longint;
var
  i,zzz:longint;
begin
  f[x]:=true; zzz:=0;
  for i:=e[x]+1 to e[x+1] do
  if not f[d[i,2]] then
  begin
    b[d[i,0]]:=dfs(d[i,2]);
    zzz:=zzz+b[d[i,0]];
  end;
  zzz:=zzz+1;
  exit(zzz);
end;
function fac(x:int64):int64;
begin
  if x>2 then exit(x*(x-1)*(x-2));
  exit(0);
end;
begin
  readln(n);
  for i:=1 to n-1 do
  begin
    readln(c[i,1],c[i,2],a[i]);
    c[i+n-1,1]:=c[i,2];c[i+n-1,2]:=c[i,1];c[i+n-1,0]:=i;
    inc(e[c[i,1]]);inc(e[c[i,2]]);c[i,0]:=i;
  end;
  for i:=2 to n+1 do e[i]:=e[i]+e[i-1];
  for i:=1 to 2*n-2 do
  begin d[e[c[i,1]]]:=c[i]; dec(e[c[i,1]]); end;
  dfs(1);
  for i:=1 to n-1 do
  begin
    ans1:=ans1+a[i];
    ans2:=ans2+(fac(b[i])+fac(n-b[i]))*a[i];
    k:=ans2 div fac(n);
    ans1:=ans1-k;
    ans2:=ans2-k*fac(n);
  end;
  readln(k);
  for i:=1 to k do
  begin
    readln(p,s);
    ans1:=ans1+(s-a[p]);
    ans2:=ans2+(fac(b[p])+fac(n-b[p]))*(s-a[p]);
    k:=ans2 div fac(n);
    ans1:=ans1-k;
    ans2:=ans2-k*fac(n);
    a[p]:=s;
    writeln(2*(ans1-ans2/fac(n)):0:10);
  end;
end.