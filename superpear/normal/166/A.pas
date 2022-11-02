var s,i,n,k,j:longint;
    a,b:array[0..1000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n,k);
  for i:=1 to n do
    readln(a[i],b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i]<a[j]) or ((a[i]=a[j]) and (b[i]>b[j])) then
        begin
          swap(a[i],a[j]);
          swap(b[i],b[j]);
        end;
  s:=0;
  for i:=1 to n do
    if (a[i]=a[k]) and (b[i]=b[k]) then inc(s);
  writeln(s);
end.