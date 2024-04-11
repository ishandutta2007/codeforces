program a110;

{$APPTYPE CONSOLE}

var a: array[1..1000] of longint;
    s: string;
    r, n, l, p, j, i, m, kol, sumv, sumh, ii: longint;
    area: extended;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  for i := 1 to n do read(a[i]);
  for i := 1 to n - 1 do for j := 1 to n - i do
  if a[j] < a[j + 1] then begin m := a[j]; a[j] := a[j+1]; a[j+1] := m; end;
  area := 0;
  i := 1;
  while i <= n do
  begin
    r := a[i];
    if i mod 2 = 1 then area := area + pi * a[i] * a[i] else area := area - pi * a[i] * a[i];
    inc(i);
  end;
  write(area:0:9);
end.