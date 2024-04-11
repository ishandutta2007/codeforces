var a,b,c,tot,up,m1:array[0..300000] of longint;
    n,i,o,left,right,mid,min:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,x:longint;
  begin
    i:=l;
    j:=r;
    x:=c[l+random(r-l+1)];
    repeat
      while c[i]<x do inc(i);
      while x<c[j] do dec(j);
      if i<=j then
        begin
          swap(c[i],c[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  randomize;

  readln(n);
  o:=0;
  for i:=1 to n do
    begin
      readln(a[i],b[i]);
      inc(o);
      c[o]:=a[i];
      inc(o);
      c[o]:=b[i];
    end;
  sort(1,o);
  m1[1]:=1;
  for i:=2 to o do
    if c[i]=c[i-1] then m1[i]:=m1[i-1] else m1[i]:=m1[i-1]+1;
  for i:=1 to n do
    begin
      left:=1;
      right:=o;
      repeat
        mid:=(left+right) div 2;
        if a[i]=c[mid] then break;
        if a[i]>c[mid] then left:=mid+1 else right:=mid-1;
      until left>right;
      a[i]:=m1[mid];
      left:=1;
      right:=o;
      repeat
        mid:=(left+right) div 2;
        if b[i]=c[mid] then break;
        if b[i]>c[mid] then left:=mid+1 else right:=mid-1;
      until left>right;
      b[i]:=m1[mid];
    end;
  fillchar(tot,sizeof(tot),0);
  fillchar(up,sizeof(up),0);
  for i:=1 to n do
    begin
      inc(tot[a[i]]);
      if a[i]<>b[i] then inc(tot[b[i]]);
      inc(up[a[i]]);
    end;
  //for i:=1 to n do writeln(a[i],' ',b[i]);
  min:=maxlongint;
  for i:=1 to m1[o] do
    if tot[i]*2>=n then
      if (n+1) div 2-up[i]<min then
        begin
          min:=(n+1) div 2-up[i];
          if min<0 then min:=0;
        end;
  if min=maxlongint then writeln(-1) else writeln(min);
end.