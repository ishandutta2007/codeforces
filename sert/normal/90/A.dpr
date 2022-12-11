program oject1;

{$APPTYPE CONSOLE}

var i: longint;
    a: array[0..2] of longint;
begin
  i := 0;
  read(a[1],a[2],a[0]);
  while a[1] + a[2] + a[0] > 0 do
  begin
    inc(i);
    if a[i mod 3] = 1 then a[i mod 3] := 0;
    if a[i mod 3] >= 2 then a[i mod 3] := a[i mod 3] - 2;
  end;
  write(i + 30 - 1);
  readln(i);
end.