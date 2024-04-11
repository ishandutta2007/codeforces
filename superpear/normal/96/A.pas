var s,c:string;
    i,ls:longint;
begin
  readln(s);
  ls:=length(s);
  for i:=1 to ls-6 do
    begin
      c:=copy(s,i,7);
      if (c='0000000') or (c='1111111') then
        begin
          writeln('YES');
          halt;
        end;
    end;
  writeln('NO');
end.