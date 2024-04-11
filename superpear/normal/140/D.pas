var a:array[0..10000] of longint;
    n,i,j,o,k,ans:longint;

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
  o:=10;
  k:=n;
  for i:=1 to n do
    if o+a[i]>720 then
      begin
        k:=i-1;
        break;
      end
    else
      o:=o+a[i];
  write(k,' ');
  ans:=0;
  o:=10;
  for i:=1 to k do
    begin
      o:=o+a[i];
      if o>=360 then ans:=ans+o-360;
    end;
  writeln(ans);
end.