program vkb;

{$APPTYPE CONSOLE}

var a: array[1..4] of longint;
    k, n, h, kol: longint;
    i, j: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  a[1] := 0;
  a[2] := 0;
  a[3] := 0;
  a[4] := 0;
  kol := 0;
  for i := 1 to n do
  begin
    read(k);
    inc(a[k]);
  end;
  kol := a[4];
  kol := kol + a[3];
  a[1] := a[1] - a[3];
  if a[1] < 0 then
    a[1] := 0;
  h := a[2] * 2 + a[1];
  kol := kol + (h + 3) div 4;
  write(kol);
end.