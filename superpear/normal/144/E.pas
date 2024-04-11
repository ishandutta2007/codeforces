var x,y,z,ans,f:array[0..200000] of longint;
    m,n,i,xc,yc,o,mini,left,right,mid,e:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,c,d,e:longint;
  begin
    i:=l;
    j:=r;
    e:=l+random(r-l+1);
    c:=x[e];
    d:=y[e];
    repeat
      while (y[i]<d) or ((y[i]=d) and (x[i]<c)) do inc(i);
      while (d<y[j]) or ((d=y[j]) and (c<x[j])) do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          swap(z[i],z[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure sort2(l,r:longint);
  var i,j,c,e:longint;
  begin
    i:=l;
    j:=r;
    e:=l+random(r-l+1);
    c:=ans[e];
    repeat
      while ans[i]<c do inc(i);
      while c<ans[j] do dec(j);
      if i<=j then
        begin
          swap(ans[i],ans[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort2(l,j);
    if i<r then sort2(i,r);
  end;

function low(s:longint):longint;
  begin
    exit(s and (-s));
  end;

procedure plus(s,num:longint);
  begin
    while s<=n do
      begin
        inc(f[s],num);
        s:=s+low(s);
      end;
  end;

function sum(s:longint):longint;
  var e:longint;
  begin
    e:=0;
    while s>0 do
      begin
        inc(e,f[s]);
        s:=s-low(s);
      end;
    exit(e);
  end;

begin
  randomize;
  readln(n,m);
  for i:=1 to m do
    begin
      readln(xc,yc);
      x[i]:=n+1-yc;
      y[i]:=xc;
      z[i]:=i;
    end;
  sort(1,m);
  fillchar(ans,sizeof(ans),0);
  o:=0;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do plus(i,1);
  for i:=1 to m do
    begin
      e:=sum(x[i]-1);
      if sum(y[i])>e then
        begin
          inc(o);
          ans[o]:=z[i];
          left:=x[i];
          right:=y[i];
          repeat
            mid:=(left+right) div 2;
            if sum(mid)>e then right:=mid-1 else left:=mid+1;
          until left>right;
          plus(left,-1);
        end;
    end;
  sort(1,o);
  writeln(o);
  for i:=1 to o-1 do write(ans[i],' ');writeln(ans[o]);
end.