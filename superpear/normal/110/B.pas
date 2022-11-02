var i,n:longint;
begin
  readln(n);
  for i:=1 to n do
    write(chr((i-1) mod 4+97));
  writeln;
end.