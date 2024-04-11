var n,i,ans,max,k,min:longint;
    a:array[0..10000] of longint;

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
  ans:=0;
  max:=0;
  for i:=1 to n do
    if a[i]>max then
      begin
        max:=a[i];
        k:=i;
      end;
  for i:=k downto 2 do
    swap(a[i],a[i-1]);
  ans:=ans+k-1;
  min:=maxlongint;
  for i:=n downto 1 do
    if a[i]<min then
      begin
        min:=a[i];
        k:=i;
      end;
  ans:=ans+n-k;
  writeln(ans);
end.