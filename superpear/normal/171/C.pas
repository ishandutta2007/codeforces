var n,i,s,c:longint;
begin
  read(n);
  for i:=1 to n do
    begin
      read(c);
      s:=s+c*i;
    end;
  writeln(s);
end.