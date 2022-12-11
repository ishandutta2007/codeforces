program C91;

{$APPTYPE CONSOLE}

function min (a, b: int64): int64;
begin
  if a < b then min := a else min := b;
end;

Var n, i: longint;
    s: string;
    p, a4, a7: longint;
    code: integer;
    k, l, r, pr, kol, num: int64;
    sum: int64;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  readln(l, k);
  read(s);
  if k = 0 then
  begin
    write(s);
    halt;
  end;
  for i := 1 to l - 1 do
    if (s[i] = '4') and (s[i + 1] = '7') then
    begin
      if i mod 2 = 1 then
      begin
        dec(k);
        s[i + 1] := '4';
      end
      else
        if (i > 1) and (s[i - 1] = '4') then
        begin
          if k mod 2 = 1 then
            s[i] := '7';
          write(s);
          halt;
        end
        else
        begin
          s[i] := '7';
          dec(k);
        end;
      if k = 0 then
      begin
        write(s);
        halt;
      end;
    end;
  write(s);
end.