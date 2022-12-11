var i, n, m, k: longint;
    s: string;
begin

read(s);
i := 1;
while i < length(s) do
begin
  if (s[i] = ' ') and (s[i+1] in [' ','.',',','!','?']) then begin delete(s,i,1); dec(i); end;
  if (s[i] in ['.',',','!','?']) and (s[i+1] <> ' ') then begin insert(' ',s,i+1); inc(i); end;
  inc(i);
end;
write(s);
end.