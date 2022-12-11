var i, k, n, t, q, a, b, r1, r2: longint;
s: string;
begin

readln(n);
read(s);

for i := 1 to n do
begin
  if i mod 2 = 0 then if s[i] = '1' then inc(a);
  if i mod 2 = 1 then if s[i] = '1' then inc(b);
end;

r1 := a + (n + 1) div 2 - b;
r2 := b + n div 2 - a;

if r1 < r2 then write(r1) else write(r2);
end.