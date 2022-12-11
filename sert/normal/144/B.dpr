const eps = 0.000000001;

procedure swap(var a, b: longint);
var c: longint;
begin
  c := a; a := b; b := c;
end;

var x, y, r: array[1..100000] of longint;
    n, k, i, j, max, min, x1, x2, y1, y2, kol: longint;
    s: string;
    fail: boolean;

begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(x1, y1, x2, y2);
read(n);
kol := 0;
for i := 1 to n do begin read(x[i], y[i], r[i]); end;
if x1 > x2 then swap(x1, x2);
if y1 > y2 then swap(y1, y2);
for i := x1 to x2 do
begin
  fail := false;
  for j := 1 to n do
    if (i - x[j])*(i - x[j])+(y1 - y[j])*(y1 - y[j]) <= r[j] * r[j] then
     fail := true;
  if not fail then inc(kol);
end;
for i := x1 to x2 do
begin
  fail := false;
  for j := 1 to n do
    if (i - x[j])*(i - x[j])+(y2 - y[j])*(y2 - y[j]) <= r[j] * r[j] then fail := true;
  if not fail then inc(kol);
end;
for i := y1 + 1 to y2 - 1 do
begin
  fail := false;
  for j := 1 to n do
    if (x1 - x[j])*(x1 - x[j])+(i - y[j])*(i - y[j]) <= r[j] * r[j] then fail := true;
  if not fail then inc(kol);
end;
for i := y1 + 1 to y2 - 1 do
begin
  fail := false;
  for j := 1 to n do
    if (x2 - x[j])*(x2 - x[j])+(i - y[j])*(i - y[j]) <= r[j] * r[j] then fail := true;
  if not fail then inc(kol);
end;
write(kol);
end.