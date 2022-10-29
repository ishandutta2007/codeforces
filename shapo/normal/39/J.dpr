program Project2;

{$APPTYPE CONSOLE}
{$O+,I-}
uses
  SysUtils, Math;

var
  S1, s2: string;
  i, l, r: integer;

begin
  ReadLn(S1);
  ReadLn(S2);
  i := Length(S1) - 1;

  r := i + 1;

  l := 0;

  while (i >= 1) and (S2[i] = S1[i + 1]) do begin

    if S2[i] <> S1[i] then
      r := i;

    dec(i);

  end;

  l := i;

  while (i >= 1) and (S2[i] = S1[i]) do
    dec(i);

  if i <> 0 then
    r := 0;

  if r = 0 then
    l := 0;

  WriteLn(r-l);

  inc(l);

  for i := l to r do
    Write(i, ' ');

end.