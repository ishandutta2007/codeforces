var a: array[1..100002] of integer;
    n, k, i, s, t, p, j, e: longint;
    fail: string;

begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(n);
fail := 'NO';
for i := 1 to n do read(a[i]);
for e := 3 to n do
if n mod e = 0 then
begin
  k := e;


for i := 1 to n div k do
begin
  s := -1;
  t := 1;
  for j := 0 to k - 1 do
  t := t * a[i + j * (n div k)];
  if t = 1 then begin write('YES'); halt; end;
end;
end;
write(fail);
end.