var i, k, n, s, t, q: longint;
begin

read(n);
if n = 1 then begin write('1'); halt; end;
if n mod 2 = 0 then begin write('2 1'); s := 2; end;
if n mod 2 = 1 then begin write('1 3 2'); s := 3; end;
t := -1;
for i := s + 1 to n do
begin
  t := t * -1;
  write(' ', i + t);
end;
end.