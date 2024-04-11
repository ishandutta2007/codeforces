var n, i, k, s, t, j: longint;
    a, u: array[1..1000] of longint;
    str: string;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
readln(str);
read(k);
if((str = 'front')and(k=1))or((str = 'back')and(k=2))then write('L') else
write('R');
end.