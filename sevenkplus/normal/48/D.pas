var a,b,c:array[1..100000] of longint;
    n,i:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    begin
      read(b[i]);inc(a[b[i]]);
    end;
  for i:=2 to 100000 do
    if a[i]>a[i-1] then
      begin
        writeln(-1);halt;
      end;
  writeln(a[1]);
  for i:=1 to n do
    begin
      c[i]:=a[b[i]];dec(a[b[i]]);
    end;
  for i:=1 to n-1 do write(c[i],' ');writeln(c[n]);
end.