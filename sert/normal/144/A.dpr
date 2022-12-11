var a: array[1..100000] of longint;
    n, k, i, j, max, min: longint;
    s: string;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
read(n);
for i := 1 to n do read(a[i]);
max := n;
min := 1;
for i := n - 1 downto 1 do if a[i] >= a[max] then max := i;
for i := 2 to n do if a[i] <= a[min] then min := i;
if max > min then dec(max);
write(max - 1 + n - min);
end.