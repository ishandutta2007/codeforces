type two=record
           num,time:longint;
         end;

var f:array[0..1000000] of two;
    ans:array[0..1000000,0..3] of longint;
    n,i,s,q,o,a1,a2,a3:longint;
    e1,e2,e3,e:two;
    a:array[0..1000000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure swapt(var a,b:two);
  var r:two;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

function get:two;
  var o:longint;
  begin
    get:=f[1];
    f[1]:=f[s];
    s:=s-1;
    o:=1;
    while ((o*2<=s) and (f[o].time<f[o*2].time)) or
          ((o*2+1<=s) and (f[o].time<f[o*2+1].time)) do
      begin
        if (o*2+1>s) or (f[o*2].time>f[o*2+1].time) then
          begin
            swapt(f[o],f[o*2]);
            o:=o*2;
          end
        else
          begin
            swapt(f[o],f[o*2+1]);
            o:=o*2+1;
          end;
      end;
  end;

procedure put(x:two);
  var o:longint;
  begin
    s:=s+1;
    f[s]:=x;
    o:=s;
    while (o>1) and (f[o].time>f[o div 2].time) do
      begin
        swapt(f[o],f[o div 2]);
        o:=o div 2;
      end;
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
  for i:=1 to n do read(a[i]);
  sort(1,n);
  s:=0;
  fillchar(f,sizeof(f),0);
  a[n+1]:=-1;
  q:=1;
  for i:=2 to n+1 do
    if a[i]<>a[i-1] then
      begin
        e.time:=q;
        e.num:=a[i-1];
        put(e);
        q:=1;
      end
    else
      q:=q+1;
  o:=0;
  fillchar(ans,sizeof(ans),0);
  while s>=3 do
    begin
      e1:=get;
      e2:=get;
      e3:=get;
      a1:=e1.num;
      a2:=e2.num;
      a3:=e3.num;
      inc(o);
      if a1<a2 then swap(a1,a2);
      if a1<a3 then swap(a1,a3);
      if a2<a3 then swap(a2,a3);
      ans[o,1]:=a1;ans[o,2]:=a2;ans[o,3]:=a3;
      dec(e1.time);
      if e1.time>0 then put(e1);
      dec(e2.time);
      if e2.time>0 then put(e2);
      dec(e3.time);
      if e3.time>0 then put(e3);
    end;
  writeln(o);
  for i:=1 to o do
    writeln(ans[i,1],' ',ans[i,2],' ',ans[i,3]);
end.