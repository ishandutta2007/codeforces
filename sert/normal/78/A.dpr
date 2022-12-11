var s: string;
    k, n, i, j: longint;
begin
//reset (input,'i.i');
//rewrite(output,'o.o');

readln(s);
k := 0;
for i := 1 to length(s) do if (s[i] = 'o') or (s[i] = 'a') or (s[i] = 'i')
or (s[i] = 'u') or (s[i] = 'e') then inc(k);
if k <> 5 then begin write('NO'); halt; end;

readln(s);
k := 0;
for i := 1 to length(s) do if (s[i] = 'o') or (s[i] = 'a') or (s[i] = 'i')
or (s[i] = 'u') or (s[i] = 'e') then inc(k);
if k <> 7 then begin write('NO'); halt; end;

readln(s);
k := 0;
for i := 1 to length(s) do if (s[i] = 'o') or (s[i] = 'a') or (s[i] = 'i')
or (s[i] = 'u') or (s[i] = 'e') then inc(k);
if k <> 5 then begin write('NO'); halt; end;

write('YES');
//readln(j);
end.