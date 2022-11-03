var n,i,o1,o2,s1,s2:longint;
    a,w,x1,y1:array[0..200000] of longint;

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

  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      w[i]:=i;
    end;
  sort(1,n);

  o1:=0;
  o2:=0;
  s1:=0;
  s2:=0;
  for i:=1 to n-1 do
    if (i<>n) and (i mod 2=1) then
      begin
        inc(o1);inc(o2);
        if s1<=s2 then
          begin
            x1[o1]:=w[i+1];y1[o2]:=w[i];
            s1:=s1+a[i+1];s2:=s2+a[i];
          end
        else
          begin
            x1[o1]:=w[i];y1[o2]:=w[i+1];
            s1:=s1+a[i];s2:=s2+a[i+1];
          end;
      end;
  if n mod 2=1 then
    begin
      if s1<=s2 then
        begin
          inc(o1);
          x1[o1]:=w[n];
        end
      else
        begin
          inc(o2);
          y1[o2]:=w[n];
        end;
    end;
  writeln(o1);
  for i:=1 to o1-1 do write(x1[i],' ');writeln(x1[o1]);
  writeln(o2);
  for i:=1 to o2-1 do write(y1[i],' ');writeln(y1[o2]);
end.