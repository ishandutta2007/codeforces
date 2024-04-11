var k:int64;
    n,i,e,c,s:longint;
    a:array[0..200000] of longint;

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
          y:=a[i];
          a[i]:=a[j];
          a[j]:=y;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  randomize;
  readln(n,k);
  for i:=1 to n do
    read(a[i]);
  sort(1,n);
  e:=(int64(k)-1) div n+1;
  k:=(k-1) mod n+1;
  s:=0;
  for i:=1 to n do
    if a[i]=a[e] then
      begin
        inc(s);
        if i<e then k:=k+n;
      end;
  write(a[e],' ');
  writeln(a[(k-1) div s+1]);
end.