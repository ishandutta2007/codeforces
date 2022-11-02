var a,b,s:longint;
begin
  readln(a,b);
  s:=0;
  while b>0 do
    begin
      s:=s*10+b mod 10;
      b:=b div 10;
    end;
  writeln(a+s);
end.