var n, i, k, s, t, j: longint;
    a, u: array[1..1000] of longint;
    str: string;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
read(n, k);
for i :=1 to n do read(u[i]);
i := k;
while u[(i-1)mod n + 1] = 0 do
 i := i mod n + 1;
write(i);
end.