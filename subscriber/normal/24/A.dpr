var
ans, a,b,c,n,ans1,ans2,i,kk:longint;
 yy,zz,xx,pp,f:array[1..1000]of longint;

procedure rec(x,p:longint);
var
 w:longint;
begin
 f[x]:=1;
 w:=xx[x];
 while w>0 do
 begin
  if (yy[w]<>p)then
  begin
   if (p=0)and(f[yy[w]]=1)then exit;
   if zz[w]>0 then inc(ans1,zz[w]);
   if f[yy[w]]=0 then rec(yy[w],x);
  end;
  w:=pp[w];
 end;
end;

procedure recc(x,p:longint);
var
 w:longint;
begin
 f[x]:=1;
 w:=xx[x];
 while w>0 do
 begin
  if (yy[w]<>p)then
  begin
   if (p=0)and(f[yy[w]]=1)then exit;
   if zz[w]<0 then inc(ans1,-zz[w]);
   if f[yy[w]]=0 then recc(yy[w],x);
  end;
  w:=pp[w];
 end;
end;

begin
 readln(n);
 ans:=maxlongint;
 kk:=0;
 for i:=1 to n do
 begin
  readln(a,b,c);
  inc(kk);
  yy[kk]:=b;
  zz[kk]:=-c;
  pp[kk]:=xx[a];
  xx[a]:=kk;
  inc(kk);
  yy[kk]:=a;
  zz[kk]:=c;
  pp[kk]:=xx[b];
  xx[b]:=kk;
 end;
  ans1:=0;
  fillchar(f,sizeof(f),0);
  rec(1,0);
  if ans1<ans then ans:=ans1;
  ans1:=0;
  fillchar(f,sizeof(f),0);
  recc(1,0);
  if ans1<ans then ans:=ans1;
 writeln(ans);
end.