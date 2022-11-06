
program cf_2;

var
    a:array[1..100040] of longint;
    i,n,m,k:longint;
    s:int64;

begin
  readln(n,m);
  for i:= 1 to m do
    read(a[i]);
  readln;
  k:=1;
  for i:= 1 to m do
    begin
      s:=s-k+a[i];
      if a[i]<k then s:=s+n;
      k:=a[i];
    end;
  writeln(s);
end.