const bigp=1000000007;

var a,c,v:array[0..100000] of longint;
    n,k,o,i,xc,j,q,ans,s:longint;
    f:array[0..2000,0..2000] of longint;

function lucky(s:longint):boolean;
  begin
    while s>0 do
      begin
        if (s mod 10<>4) and (s mod 10<>7) then exit(false);
        s:=s div 10;
      end;
    exit(true);
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,x,y:longint;
  begin
    i:=l;
    j:=r;
    x:=a[l+random(r-l+1)];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if i<=j then
        begin
          swap(a[i],a[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function pow(a,b:longint):longint;
  var d:longint;
  begin
    if b=0 then exit(1);
    d:=pow(a,b div 2);
    d:=int64(d)*d mod bigp;
    if b mod 2=1 then d:=int64(d)*a mod bigp;
    exit(d);
  end;

begin
  randomize;

  readln(n,k);
  o:=0;
  for i:=1 to n do
    begin
      read(xc);
      if lucky(xc) then
        begin
          inc(o);
          a[o]:=xc;
        end;
    end;

  sort(1,o);
  fillchar(v,sizeof(v),0);
  q:=0;
  a[0]:=-1;
  for i:=1 to o do
    if a[i]<>a[i-1] then
      begin
        inc(q);
        v[q]:=1;
      end
    else
      inc(v[q]);
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  for i:=1 to q do
    begin
      f[i,0]:=1;
      for j:=1 to i do
        f[i,j]:=(f[i-1,j]+int64(f[i-1,j-1])*v[i]) mod bigp;
    end;

  s:=n-o;
  c[0]:=1;
  for i:=1 to s do
    begin
      c[i]:=int64(c[i-1])*(s-i+1) mod bigp;
      c[i]:=(int64(c[i])*pow(i,bigp-2)) mod bigp;
    end;

  ans:=0;
  for i:=0 to q do
    if i<=k then
      ans:=(ans+int64(f[q,i])*c[k-i]) mod bigp;
  writeln(ans);
end.