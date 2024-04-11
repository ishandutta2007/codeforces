var a,b:array[0..100000] of longint;
    n,d,i,x1,y1,a1,b1,e:longint;

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
          swap(b[i],b[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  randomize;

  readln(n,d);
  readln(a1,b1);
  for i:=1 to n do
    begin
      readln(x1,y1);
      a[i]:=x1*a1+y1*b1;
      b[i]:=i;
    end;
  sort(1,n);
  e:=0;
  while (e<n) and (d>=a[e+1]) do
    begin
      dec(d,a[e+1]);
      inc(e);
    end;
  writeln(e);
  if e>0 then
    begin
      for i:=1 to e-1 do write(b[i],' ');writeln(b[e]);
    end;
end.