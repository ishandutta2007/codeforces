var s, ed: string; n, i, k, p: longint;
begin
readln(s);
ed := '1';
k := 0;
while s <> '1' do
begin
  inc(k);
  if s[length(s)] = '0' then delete(s, length(s), 1) else
  begin
    s[length(s)] := '0';
    p := length(s) - 1;
    while (s[p] = '1')and(p > 0) do
    begin
      dec(p);
      s[p+1] := '0';
    end;
    if p > 0 then
    s[p] := '1'
    else insert(ed, s, 1);
  end;
end;
write(k);
end.