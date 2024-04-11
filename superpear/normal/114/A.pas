var a,b,s:longint;
begin
  readln(a);
  readln(b);
  s:=0;
  while b mod a=0 do
    begin
      inc(s);
      b:=b div a;
    end;
  dec(s);
  if b<>1 then writeln('NO')
  else
    begin
      writeln('YES');
      writeln(s);
    end;
end.