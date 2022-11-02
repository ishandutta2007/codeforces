var n,i,j,max:longint;
    a,c:array[0..100000] of longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  max:=-maxlongint;
  for i:=1 to n do
    if (n mod i=0) and (n div i>=3) then
      begin
        fillchar(c,sizeof(c),0);
        for j:=1 to n do
          inc(c[(j-1) mod i+1],a[j]);
        for j:=1 to i do
          if c[j]>max then max:=c[j];
      end;
  writeln(max);
end.