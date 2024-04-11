program C98_1;

{$APPTYPE CONSOLE}

var s, k: string;
    i, n, a, kol: longint;
begin
read(s);
k := '';
kol := 0;
i := 1;
while i <= length(s) do
begin
  if (length(k) <> 5) and ((length(k) = 0) or (k[length(k)] = s[i])) then k := k + s[i] else
  begin k := ''; inc(kol); dec(i); end;
  inc(i);
end;
if k <> '' then inc(kol);
write(kol);
end.