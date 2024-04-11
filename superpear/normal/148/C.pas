var n,a,b,s,i:longint;
    f:array[0..1000] of longint;
begin
  readln(n,a,b);
  f[1]:=1;
  s:=1;
  for i:=2 to b+1 do
    begin
      f[i]:=s+1;
      s:=s+f[i];
    end;
  if (b=0) and (a>0) then
    begin
      f[2]:=1;
      inc(b);
    end;
  for i:=b+2 to b+a+1 do
    f[i]:=f[i-1]+1;
  if b+a+1>n then
    begin
      writeln(-1);
      halt;
    end;
  for i:=b+a+2 to n do f[i]:=1;
  for i:=1 to n-1 do write(f[i],' ');writeln(f[n]);
end.