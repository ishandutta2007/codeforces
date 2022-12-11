program dinamka;

{$APPTYPE CONSOLE}

var s1, s: array[1..100] of string [105];
    n, k, i, j, u: longint;
    st, iz: string;
begin

read(n);
for i := 1 to n do
if i mod 2 = 1 then write((i+1)div 2,' ')else
write(n - (i-1) div 2, ' ');

end.