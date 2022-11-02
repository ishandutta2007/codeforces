var n,i,j,e,s:longint;
    a,b:array[0..10000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n);
  for i:=1 to n do
    readln(a[i],b[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      if (b[i]<b[j]) or ((b[i]=b[j]) and (a[i]<a[j])) then
        begin
          swap(a[i],a[j]);
          swap(b[i],b[j]);
        end;
  e:=1;
  s:=0;
  for i:=1 to n do
    if e>=1 then
      begin
        s:=s+a[i];
        e:=e-1+b[i];
      end;
  writeln(s);
end.