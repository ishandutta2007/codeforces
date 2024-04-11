program Chat;
var hello, msg: string;
i, h: integer;
begin
  readln(msg);
  h:=0;
  hello:='hello';
  for i:=1 to length(msg) do
    if (h<5) then
      if (msg[i] = hello[h+1]) then h:=h+1;
  if (h=5) then writeln('YES') else writeln('NO');
end.