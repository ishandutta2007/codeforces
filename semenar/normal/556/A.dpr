program Nullandone;
var n, i, nulls, ones: integer;
ch: char;
begin
  readln(n);
  nulls := 0;
  ones := 0;
  for i:=1 to n do
    begin
    read(ch);
    if (ch = '0') then nulls := nulls+1 else ones := ones+1;
    end;
  if (nulls > ones) then writeln(nulls-ones) else writeln(ones-nulls);
end.