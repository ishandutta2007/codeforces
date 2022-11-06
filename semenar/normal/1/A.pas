program Teatr;
var n, m, a, b, c, i, j, ans_length: integer;
ab, ac, ans: array [1..20] of integer;
begin
read(n,m,a);
b:=n div a;
if ((n mod a) > 0) then b:=b+1;
c:=m div a;
if ((m mod a) > 0) then c:=c+1;
for i:=1 to 10 do
  begin
  ab[i]:=b mod 10;
  b:=b div 10;
  ac[i]:=c mod 10;
  c:=c div 10;
  end;
for i:=1 to 20 do
  ans[i]:=0;
for i:=1 to 10 do
  for j:=1 to 10 do
    ans[i+j-1]:=ans[i+j-1]+ab[i]*ac[j];
for i:=1 to 19 do
  begin
  ans[i+1]:=ans[i+1]+(ans[i] div 10);
  ans[i]:=ans[i] mod 10;
  end;
ans_length:=0;
for i:=20 downto 1 do
  if ((ans[i] > 0) and (ans_length = 0)) then
    ans_length := i;
for i:=ans_length downto 1 do
  write(ans[i]);
end.