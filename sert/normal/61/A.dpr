var s, k: string;
i: longint;
begin
readln(s);
readln(k);
for i := 1 to length(s) do
if s[i] = k[i] then write('0') else write('1');
end.