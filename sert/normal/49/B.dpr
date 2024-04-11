var n, m, k,  t, i, j, max: longint;
    rez: int64;
    a: array[1..10000] of longint;
    s: string;

begin

read(n, m);
max := 0;
t := n;
while t > 0 do
begin
  if t mod 10 > max then max := t mod 10;
  t := t div 10;
end;
t := m;
while t > 0 do
begin
  if t mod 10 > max then max := t mod 10;
  t := t div 10;
end;

i := 1;
inc(max);
while n > 0 do
begin
  rez := rez + (n mod 10) * i;
  i := i * max;
  n := n div 10;
end;

i := 1;
while m > 0 do
begin
  rez := rez + (m mod 10) * i;
  i := i * max;
  m := m div 10;
end;

i := 1;
j := 1;
while i <= rez do
begin
  i := i * max;
  inc(j);
end;
write(j-1);

end.