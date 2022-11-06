
program cf201_2;

var
    a:array[0..100020] of longint;
    i,j,k,l,m,n:longint;
    f:boolean;

begin
  readln(n);
  k:=0;
  for i:= 0 to n-1 do
    begin
      read(a[i]);
      if a[i]=i then inc(k);
    end;
  readln;
  if k=n then writeln(k) else begin
    f:=false;
    for i:= 0 to n-1 do
      if (a[i]<>i) and (a[a[i]]=i) then f:=true;
    if f then writeln(k+2) else writeln(k+1);
  end;
end.