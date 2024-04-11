var a,b:array[0..200000] of longint;
    n,i,max,ans:longint;

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

  readln(n);
  for i:=1 to n do
    readln(a[i],b[i]);
  sort(1,n);

  ans:=0;
  max:=0;
  for i:=1 to n do
    begin
      if b[i]<max then inc(ans);
      if b[i]>max then max:=b[i];
    end;
  writeln(ans);
end.