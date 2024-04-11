const maxn=200005;

var n,i:longint;
    a:array[0..maxn] of longint;

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
  readln(n);
  for i:=1 to n do
    read(a[i]);
  sort(1,n);
  if a[n]=1 then
    begin
      for i:=1 to n-1 do write(1,' ');
      writeln(2);
    end
  else
    begin
      write(1);
      for i:=2 to n do
        write(' ',a[i-1]);
      writeln;
    end;
end.