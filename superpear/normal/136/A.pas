var n,i,xc:longint;
    a:array[0..100000] of longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(xc);
      a[xc]:=i;
    end;
  for i:=1 to n-1 do write(a[i],' ');writeln(a[n]);
end.