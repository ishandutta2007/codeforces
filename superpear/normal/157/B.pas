var n,i,j,e:longint;
    a:array[0..1000] of longint;

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
    read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then swap(a[i],a[j]);
  e:=0;
  for i:=n downto 1 do
    if (n-i) mod 2=0 then e:=e+a[i]*a[i] else e:=e-a[i]*a[i];
  writeln(e*pi:0:15);
end.