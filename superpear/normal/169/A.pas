var n,a,b,i,j:longint;
    f:array[0..10000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n,a,b);
  for i:=1 to n do
    read(f[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      if f[i]<f[j] then swap(f[i],f[j]);
  writeln(f[a]-f[a+1]);
end.