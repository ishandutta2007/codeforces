var a,b:array[0..120000] of longint;
    s:array[0..120000] of int64;
    d,e:int64;
    n,k,i:longint;

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
    x:=b[l+random(r-l+1)];
    repeat
      while b[i]>x do inc(i);
      while x>b[j] do dec(j);
      if i<=j then
        begin
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
  readln(n,k);
  readln(d);
  for i:=1 to n do
    read(a[i]);
  b:=a;
  sort(1,n-1);
  s[0]:=0;
  for i:=1 to n-1 do
    s[i]:=s[i-1]+int64(b[i]);
  s[n]:=s[n-1];
  for i:=1 to n-1 do
    begin
      e:=s[k];
      if a[i]<b[k] then
        e:=s[k-1]+int64(a[i]);
      if e>d then
        begin
          writeln(i);
          halt;
        end;
    end;
  writeln(n);
end.