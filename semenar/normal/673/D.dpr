program Round3div2;
var n, i, k, a, b, c, d, max1, max2: integer;

begin
  readln(n, k);
  readln(a, b, c, d);
  if (k < n+1) then writeln(-1) else
    if (n = 4) then writeln(-1) else
      if (n = 5) then
        begin
        for i:=1 to 5 do
          if not((i=a) or (i=b) or (i=c) or (i=d)) then max1:=i;
        writeln(a, ' ', d, ' ', max1, ' ', c, ' ', b);
        writeln(c, ' ', b, ' ', max1, ' ', a, ' ', d);
        end
      else
        begin
        for i:=1 to n do
          if not((i=a) or (i=b) or (i=c) or (i=d)) then max1:=i;
        for i:=1 to n do
          if not((i=a) or (i=b) or (i=c) or (i=d) or (i=max1)) then max2:=i;
        write(a, ' ', d, ' ', max1, ' ');
        for i:=1 to n do
          if not((i=a) or (i=b) or (i=c) or (i=d) or (i=max1) or (i=max2)) then write(i, ' ');
        writeln(max2, ' ', c, ' ', b);
        write(c, ' ', b, ' ', max2, ' ');
        for i:=n downto 1 do
          if not((i=a) or (i=b) or (i=c) or (i=d) or (i=max1) or (i=max2)) then write(i, ' ');
        writeln(max1, ' ', a, ' ', d);
        end;
end.