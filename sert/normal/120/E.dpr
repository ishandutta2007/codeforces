var n, i, a: longint;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
read(n);
for i := 1 to n do
begin
read(a);
writeln((a+1)mod 2);
end;
end.