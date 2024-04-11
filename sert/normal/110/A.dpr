var   n: int64;
      i, k, j, m, f: int64;

begin

n := 0;
k := 0;
f := 0;
i := 0;
read(n);
while n > 0 do
begin
if (n mod 10 = 4) or (n mod 10 = 7) then inc(k);
n := n div 10;
end;
f := 0;
if k = 0 then f := 1;
while k > 0 do
begin
if (k mod 10 <> 4) and (k mod 10 <> 7) then f := 1;
k := k div 10;
end;
if f = 1 then write('NO') else write('YES');
end.