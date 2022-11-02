var n,i,j,c,o:longint;
a:array[0..1000,0..1000] of longint;
begin
  readln(n);
  c:=1;
  while c*(c+1) div 2<=n do inc(c);
  dec(c);
  writeln(c+1);
  o:=0;
  for i:=1 to c do
    for j:=1 to i do
      begin
        inc(o);
        a[j,i]:=o;
      end;
  o:=0;
  for i:=2 to c+1 do
    for j:=1 to i-1 do
      begin
        inc(o);
        a[i,j]:=o;
      end;
  for i:=1 to c+1 do
    begin
      for j:=1 to c-1 do
        write(a[i,j],' ');
      writeln(a[i,c]);
    end;
end.