program africand;

{$APPTYPE CONSOLE}

var x, a, b, c, i, k, low, hi, j, max: longint;
    d : array [1..10000] of longint;
    sa, sb, sc: string;
    code: integer;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');

  read(a);
  read(b);

  c := a mod b;

  while c <> 0 do
  begin
    a := b;
    b := c;
    c := a mod b;
  end;
  x := 0;
  for i := 1 to round(sqrt(b)) do
  if b mod i = 0 then
    if i * i = b then begin inc(x); d[x] := i; end
    else begin x := x + 2; d[x - 1] := i; d[x] := b div i; end;
  read(k);
  for i := 1 to k do begin
    read(low, hi);
    max := -1;
    for j := 1 to x do if (d[j] >= low) and (d[j] <= hi) and (d[j] > max) then
    max := d[j];
    writeln(max);
  end;

end.