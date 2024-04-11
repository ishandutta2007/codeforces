var x,y,xb,yb,w,ans,ok:array[0..200000] of longint;
    n,i:longint;

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
    c:=x[e];d:=y[e];
    repeat
      while (x[i]<c) or ((x[i]=c) and (y[i]<d)) do inc(i);
      while (c<x[j]) or ((c=x[j]) and (d<y[j])) do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          swap(w[i],w[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  randomize;
  readln(n,n);
  fillchar(ans,sizeof(ans),0);
  for i:=1 to n do
    begin
      readln(x[i],y[i]);
      w[i]:=i;
    end;
  xb:=x;yb:=y;
  sort(1,n);
  x[0]:=maxlongint;x[n+1]:=maxlongint;
  for i:=1 to n do
    begin
      if x[i]=x[i-1] then inc(ans[w[i]]);
      if x[i]=x[i+1] then inc(ans[w[i]]);
    end;
  for i:=1 to n do swap(x[i],y[i]);
  sort(1,n);
  x[0]:=maxlongint;x[n+1]:=maxlongint;
  for i:=1 to n do
    begin
      if x[i]=x[i-1] then inc(ans[w[i]]);
      if x[i]=x[i+1] then inc(ans[w[i]]);
    end;
  for i:=1 to n do
    begin
      x[i]:=xb[w[i]]+yb[w[i]];
      y[i]:=xb[w[i]];
    end;
  sort(1,n);
  x[0]:=maxlongint;x[n+1]:=maxlongint;
  for i:=1 to n do
    begin
      if x[i]=x[i-1] then inc(ans[w[i]]);
      if x[i]=x[i+1] then inc(ans[w[i]]);
    end;
  for i:=1 to n do
    begin
      x[i]:=xb[w[i]]-yb[w[i]];
      y[i]:=xb[w[i]];
    end;
  sort(1,n);
  x[0]:=maxlongint;x[n+1]:=maxlongint;
  for i:=1 to n do
    begin
      if x[i]=x[i-1] then inc(ans[w[i]]);
      if x[i]=x[i+1] then inc(ans[w[i]]);
    end;
  fillchar(ok,sizeof(ok),0);
  for i:=1 to n do inc(ok[ans[i]]);
  for i:=0 to 7 do write(ok[i],' ');writeln(ok[8]);
end.