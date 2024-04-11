var a:array[0..100000] of longint;
    i,n:longint;

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
    x:=a[(l+r) div 2];
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

begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  sort(1,n);
  for i:=2 to n do
    if (a[i]<>a[i-1]) and (a[i]<a[i-1]*2) then
      begin
        writeln('YES');
        halt;
      end;
  writeln('NO');
end.