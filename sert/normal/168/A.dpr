var x, n, y: integer;
    e: extended;
begin
  read(n, x, y);
  e := n * y / 100 - x;
  if (e - 0.00000001 < 0) then
    write('0')
  else
    write(round(e + 0.5 - 0.0000001));
end.