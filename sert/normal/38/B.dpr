var u:array[-2..10, -2..10] of integer;
a: array[1..4] of integer;
i, n, k, j, m, p, xl, yl, xk, yk: longint;
cl, ck: char;
begin

readln(cl, yl);
read(ck, yk);
xl := ord(cl)-ord('a')+1;
xk := ord(ck) - ord('a')+1;
k := 0;
a[1] := -2;
a[2] := -1;
a[3] := 1;
a[4] := 2;
for i := 1 to 8 do
for j := 1 to 8 do
begin
  m := 1;
  if (i = 2)and(j=3)then
  m := m mod 2;
  if (i = xk)and(j = yk) then m := 0;
  if i = xl then m := 0;
  if j = yl then m := 0;
  for p := 1 to 4 do
  begin
    if i = a[p]+xk then
    if (j = yk + ((abs(a[p])) mod 2) + 1)or
    (j = yk - abs(a[p]) mod 2 - 1) then
    m := 0;
    if i = a[p]+xl then
    if (j = yl + ((abs(a[p])) mod 2) + 1)or
    (j = yl - abs(a[p]) mod 2 - 1) then
    m := 0;

  end;
  k := k + m;
end;
write (k);

end.