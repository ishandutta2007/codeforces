program IWBG;
var i, n, p, q, tmp: integer;
levels, all_levels: string;
begin
readln(n);
levels:='';
all_levels:='';
for i:=1 to n do
  begin
  levels:=levels+'0';
  all_levels:=all_levels+'1';
  end;
read(p);
for i:=1 to p do
  begin
  read(tmp);
  levels[tmp]:='1';
  end;
read(q);
for i:=1 to q do
  begin
  read(tmp);
  levels[tmp]:='1';
  end;
if (levels=all_levels) then writeln('I become the guy.') else writeln('Oh, my keyboard!')
end.