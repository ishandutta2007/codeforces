var tt,n:longint;
begin
  readln(tt);
  for tt:=1 to tt do
    begin
      readln(n);
      if n=1 then writeln(0) else writeln(n-2);
    end;
end.