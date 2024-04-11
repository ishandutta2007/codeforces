program a1;
var s:string;
n,l,m,k,i,j:integer;
begin
read(n);
for i:=0 to n do
begin
for j:=1 to 2*(n-i) do
write(' ');
for j:=0 to i-1 do
write(j,' ');
for j:=i downto 1 do
write(j,' ');
writeln(0);
end; 
for i:=n-1 downto 0 do
begin
for j:=1 to 2*(n-i) do
write(' ');
for j:=0 to i-1 do
write(j,' ');
for j:=i downto 1 do
write(j,' ');
writeln(0);
end;
end.