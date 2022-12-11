program C105;

{$APPTYPE CONSOLE}

const eps = 0.0000001;

var s: string;
  a, b, vd, vp, m, l, k, d, kol, n, i, j, t, f, c: longint;
  x, xp: extended;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n, a, b);
  if (n = 1) and (a = 0) and (b = 0) then begin write(1); halt; end;
  if (a = n - 1) and (b = 0) then begin write(-1); halt; end;
  if (a = 0) and (b = 0) then
  begin
    for i := n downto 1 do write(i, ' ');
    halt;
  end;
  if (b = 0) then begin for i := 1 to n - a - 1 do write('1 ');
  for i := 1 to a + 1 do write(i, ' '); halt; end;
  write('1');
  m := 1;
  for i := 2 to b + 1 do
  begin
    m := m * 2;
    write(' ', m);
  end;

  for i := 1 to a do
    write(' ', m + i);
  for i := a + b + 2 to n do write(' 1');
end.