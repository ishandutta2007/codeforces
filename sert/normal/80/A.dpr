var j, m, i, k, n, t, q, a, b, r1, r2: longint;
s: string;
begin

read(n, m);
for i := n+1 to m-1 do
begin
  a := 0;
  for j := 2 to 10 do
    if (i mod j = 0)and(i <> j) then a:=1;
    if a = 0 then begin write('NO'); halt; end;
end;

a := 0;
for j := 2 to 10 do if (m mod j = 0)and(i<>j) then begin write('NO'); halt; end;
write('YES');
end.