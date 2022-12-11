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
    l, r, pr, kol, num: int64;
    sum: int64;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(l, r);
  sum := 0;
  s := '4';
  pr := l - 1;
  while length(s) <= 10 do
  begin
    val(s, num, code);
    if num > pr then
    begin
      sum := sum + num * (min(num, r) - pr);
      if num >= r then begin write(sum); halt; end;
      pr := num;
    end;
    p := 0;
    if s = '7' then s := '44' else
    begin
      if s[length(s)] = '4' then s[length(s)] := '7' else begin s[length(s)] := '4'; p := 1; end;
      for i := length(s) - 1 downto 2 do
        if (p = 1) then if (s[i] = '7') then s[i] := '4' else begin s[i] := '7'; p := 0; end;
      if p = 1 then if s[1] = '4' then s[1] := '7' else begin s[1] := '4'; s := '4' + s; end; 
    end;
  end;

end.