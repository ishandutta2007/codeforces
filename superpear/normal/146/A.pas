var n,i,s:longint;
    ch:char;
begin
  readln(n);
  s:=0;
  for i:=1 to n do
    begin
      read(ch);
      if (ch<>'4') and (ch<>'7') then
        begin
          writeln('NO');
          halt;
        end;
      if i<=n div 2 then s:=s+ord(ch) else s:=s-ord(ch);
    end;
  if s=0 then writeln('YES') else writeln('NO');
end.