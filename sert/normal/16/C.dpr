program C98_2;

{$APPTYPE CONSOLE}

var
    i, n, kol, q: int64;
    a, b, x, y, z, k, xx, yy: int64;
    p: array[1..100000] of longint;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(a, b, x, y);
xx := x;
yy := y;
q := xx mod yy;
while q <> 0 do
begin
  xx := yy;
  yy := q;
  q := xx mod yy;
end;
x := x div yy;
y := y div yy;
if a * y > b * x then begin k := (b div y) * y; z := (b div y)*x; end
else begin z := (a div x)*x; k := (a div x)*y; end;
write(z, ' ', k);
end.