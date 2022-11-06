
program cf201_1;

var
    a:array[0..1000] of longint;
    i,j,k,l,m,n:longint;

begin
  readln(n);
  for i:= 1 to n do
    read(a[i]);
  readln;
  for i:= 1 to n-1 do
    for j:= i+1 to n do
      if a[i]>a[j] then begin
        k:=a[i];
        a[i]:=a[j];
        a[j]:=k;
      end;
  write(a[n],' ');
  for i:= 2 to n-1 do
    write(a[i],' ');
  writeln(a[1]);
end.