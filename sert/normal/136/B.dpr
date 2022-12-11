var a, b, c: string;
    i, n, k, p, s, kol, kl: integer;
    rez: longint;
begin

read(n, k);

s := 3;
a := '';
while n > 0 do
begin
  p := n mod s;
  n := n div s;
  inc(kol);
  a := chr(p + ord('0')) + a;
end;
b := '';
while k > 0 do
begin
  p := k mod s;
  k := k div s;
  b := chr(p + ord('0')) + b;
end;
while length(b) < length(a) do b := '0' + b;
while length(a) < length(b) do a := '0' + a;
for i := length(a) downto 1 do c := chr(ord('0')+(ord(b[i])-ord(a[i])+3)mod 3) + c;
p := 1;
rez := 0;
for i := length(c) downto 1 do
begin
  rez := rez + p * (ord(c[i]) - ord('0'));
  p := p * 3;
end;
write(rez);
end.