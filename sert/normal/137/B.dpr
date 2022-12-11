program C98_2;

{$APPTYPE CONSOLE}

var s, k: string;
    i, n, kol, q: longint;
    a, b: array[1..5000] of longint;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(n);
for i := 1 to n do begin read(q); inc(a[q]); end;
kol := 0;
for i := 1 to n do if a[i] = 0 then inc(kol);
write(kol);

end.