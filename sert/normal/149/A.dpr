program a106;

{$APPTYPE CONSOLE}

var
    n, k, i, j, s, t: longint;
    a: array[1..200000] of longint;
begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  for i := 1 to 12 do read(a[i]);
  for i := 1 to 11 do
    for j := 1 to 12 - i do
    if a[j] < a[j+1] then
    begin s := a[j]; a[j] := a[j+1]; a[j+1] := s; end;
  k := 0;
  s := 0;
  while (s < n) do
  begin
    inc(k);
    s := s + a[k];
    if (k = 12) and (s < n) then begin write(-1); halt; end;
  end;
  write(k);
end.