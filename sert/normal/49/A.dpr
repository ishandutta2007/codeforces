var n, m, k,  t, i, j: longint;
    a: array[1..10000] of longint;
    s: string;

begin

readln(s);
i := length(s);
while (s[i] = '?') or (s[i] = ' ') do dec(i);
if (s[i]='a')or(s[i]='o')or(s[i]='u')or(s[i]='i')or(s[i]='e')or(s[i]='y')or
(s[i]='A')or(s[i]='O')or(s[i]='U')or(s[i]='I')or(s[i]='E')or(s[i]='Y')then
write('YES') else write('NO');

end.