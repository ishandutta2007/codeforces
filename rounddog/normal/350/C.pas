
program cf203_3;

type point=record
  x,y:longint;
end;

var
    i,j,k,l,m,n,p:longint;
    a:array[0..1000200] of point;
    x,y:array[0..10000200] of longint;

procedure swap(x,y:longint);
var
    t:point;
begin
  t:=a[x];
  a[x]:=a[y];
  a[y]:=t;
end;

procedure qsort(l,h:longint);
  var i,j:longint;
      t,m:point;
  begin
    i:=l;
    j:=h;
    m:=a[(i+j) div 2];
    repeat
      while (abs(a[i].x)<abs(m.x)) or
        (abs(a[i].x)=abs(m.x)) and (abs(a[i].y)<abs(m.y)) do
        inc(i);
      while (abs(m.x)<abs(a[j].x)) or
        (abs(m.x)=abs(a[j].x)) and (abs(m.y)<abs(a[j].y)) do
        dec(j);
      if i<=j then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          inc(i);
          dec(j);
        end;
    until i>j;
    if i<h then qsort(i,h);
    if j>l then qsort(l,j);
  end;

begin
  readln(n);
  m:=2*n;
  for i:= 1 to n do
    begin
      readln(a[i].x,a[i].y);
      if a[i].x<>0 then inc(m,2);
      if a[i].y<>0 then inc(m,2);
    end;
  for i:= 1 to n do
    swap(random(n-1)+1,random(n-1)+1);
  qsort(1,n);
  writeln(m);
  for i:= 1 to n do
    begin
      x[i]:=a[i].x;
      y[i]:=a[i].y;
    end;
  for i:= 1 to n do
    begin
      if y[i]<0 then writeln(1,' ',-y[i],' D')
      else if y[i]>0 then writeln(1,' ',y[i],' U');
      if x[i]<0 then writeln(1,' ',-x[i],' L')
      else if x[i]>0 then writeln(1,' ',x[i],' R');
      writeln(2);
      if y[i]<0 then writeln(1,' ',-y[i],' U')
      else if y[i]>0 then writeln(1,' ',y[i],' D');
      if x[i]<0 then writeln(1,' ',-x[i],' R')
      else if x[i]>0 then writeln(1,' ',x[i],' L');
      writeln(3);
    end;
end.