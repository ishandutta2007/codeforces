program C96;

{$APPTYPE CONSOLE}

var s: string;
    i: longint;
begin
  read(s);
  for i := 1 to length(s) do
    if (s[i] in ['9', 'Q', 'H']) then
    begin
      write('YES');
      halt;
    end;
  write('NO');
end.