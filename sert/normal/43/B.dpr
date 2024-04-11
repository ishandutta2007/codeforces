
var n, m, k, i, j: longint;
    u: array[1..300] of integer;
    s, t, y, fail: string;
begin

  fail := 'YES';
  k := 0;
  m := 0;
readln(s); readln(t);
for i := 1 to length(t) do
if t[i] <> ' ' then
begin
  j := 1;
  k := 1;
  while (j <= length(s)) and (k = 1) do
  begin
    if s[j] = t[i] then if u[j] = 0 then
    begin u[j] := 1; k := 2; end;
    inc(j);
  end;
  if k = 1 then begin write('NO'); halt; end;
end;
write('YES');
end.