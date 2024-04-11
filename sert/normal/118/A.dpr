var s: string;
    i, n, l: longint;

begin
read(s);
for i := 1 to length(s) do
begin
  l := 0;
  case s[i] of
   'A', 'E', 'O', 'U', 'Y', 'I', 'a', 'e', 'y', 'u', 'i', 'o': l := 1;
  end;
  if l = 0 then begin if (s[i] > 'z') or (s[i] < 'a') then
  s[i] := chr(ord(s[i])+ord('a')-ord('A'));
  write('.', s[i]);
  end;
end;
end.