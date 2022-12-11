program vka;

{$APPTYPE CONSOLE}

var a: array[1..200] of longint;
    k, n, h, kol: longint;
    i, j: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n, k);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n - 1 do
    for j := 1 to n - i do
      if a[j] < a[j + 1] then
      begin
        h := a[j];
        a[j] := a[j + 1];
        a[j + 1] := h;
      end;
  kol := 0;
  for i := 1 to n do
    if (a[i] >= a[k]) and (a[i] > 0) then
      inc(kol);
  write(kol);
end.