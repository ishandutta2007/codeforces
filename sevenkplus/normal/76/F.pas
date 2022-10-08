const maxn=500000;
var a,b,c,d,e,f,g,cc,aa,bb:array[1..maxn] of int64;
    n,i,t:longint;
    p,tmp,s,s1,s2:int64;
procedure qs(l,r:longint);
  var i,j:longint;
      x,y:int64;
  begin
    i:=l;j:=r;t:=random(r-l+1)+l;
    x:=d[t];y:=e[t];
    repeat
      while(d[i]<x)or((d[i]=x)and(e[i]<y))do inc(i);
      while(d[j]>x)or((d[j]=x)and(e[j]>y))do dec(j);
      if i<=j then
        begin
          tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
          tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
          tmp:=c[i];c[i]:=c[j];c[j]:=tmp;
          tmp:=d[i];d[i]:=d[j];d[j]:=tmp;
          tmp:=e[i];e[i]:=e[j];e[j]:=tmp;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs(i,r);
    if l<j then qs(l,j);
  end;
procedure qs1(l,r:longint);
  var i,j:longint;
      x:int64;
  begin
    i:=l;j:=r;x:=a[random(r-l+1)+l];
    repeat
      while a[i]<x do inc(i);
      while a[j]>x do dec(j);
      if i<=j then
        begin
          tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
          inc(i);dec(j);
        end;
    until i>j;
    if i<r then qs1(i,r);
    if l<j then qs1(l,j);
  end;
function fi(k:int64):longint;
  var l,r,m:longint;
  begin
    l:=1;r:=n;
    while l<=r do
      begin
        m:=(l+r) shr 1;
        if a[m]>k then r:=m-1 else
        if a[m]<k then l:=m+1 else exit(m);
      end;
  end;
function max(k:longint):longint;
  var s:int64;
  begin
    s:=0;
    while k>0 do
      begin
        if f[k]>s then s:=f[k];
        dec(k,k and (k xor (k-1)));
      end;
    max:=s;
  end;
procedure add(k:longint;l:int64);
  begin
    while k<=n do
      begin
        if l>f[k] then f[k]:=l;
        inc(k,k and (k xor (k-1)));
      end;
  end;
begin
  readln(n);
  for i:=1 to n do begin readln(cc[i],aa[i]);bb[i]:=1;end;
  readln(p);
  for i:=1 to n do begin c[i]:=cc[i];a[i]:=aa[i];b[i]:=bb[i];end;
  for i:=1 to n do
    begin
      a[i]:=a[i]*p;
      d[i]:=a[i]+c[i];e[i]:=a[i]-c[i];
    end;
  qs(1,n);
  for i:=1 to n do a[i]:=e[i];
  qs1(1,n);
  for i:=1 to n do e[i]:=fi(e[i]);
  fillchar(f,sizeof(f),0);s:=0;
  for i:=1 to n do
    begin
      g[i]:=max(e[i])+b[i];add(e[i],g[i]);
      if g[i]>s then s:=g[i];
    end;
  s2:=s;
  for i:=1 to n do begin c[i]:=cc[i];a[i]:=aa[i];b[i]:=bb[i];end;
  inc(n);c[n]:=0;a[n]:=0;b[n]:=1000000;
  for i:=1 to n do
    begin
      a[i]:=a[i]*p;
      d[i]:=a[i]+c[i];e[i]:=a[i]-c[i];
    end;
  qs(1,n);
  for i:=1 to n do a[i]:=e[i];
  qs1(1,n);
  for i:=1 to n do e[i]:=fi(e[i]);
  fillchar(f,sizeof(f),0);s:=0;
  for i:=1 to n do
    begin
      g[i]:=max(e[i])+b[i];add(e[i],g[i]);
      if g[i]>s then s:=g[i];
    end;
  s1:=s-1000000;
  writeln(s1,' ',s2);
end.