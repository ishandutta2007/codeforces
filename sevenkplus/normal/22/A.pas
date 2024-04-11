var a:array[1..100] of longint;
    n,i,min,min2:longint;
begin
  readln(n);min:=200;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]<min then min:=a[i];
    end;
  min2:=300;
  for i:=1 to n do
    if (a[i]>min) and (a[i]<min2) then min2:=a[i];
  if min2=300 then writeln('NO') else
  writeln(min2);
end.