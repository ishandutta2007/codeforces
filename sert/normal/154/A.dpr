program C109;

{$APPTYPE CONSOLE}

var s: string;
    a: array[1..15] of string[3];
    b: array[1..30] of integer;
    u: array[1..100000] of integer;
    a1, a2, kol, i, n, j, k, t, p: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  readln(s);
  readln(n);
  kol := 0;
  p := 0;
  t := 0;
  k := 0;
  for i := 1 to n do
  begin
    readln(a[i]);
    b[ord(a[i][1]) - ord('a') + 1] := i;
    b[ord(a[i][2]) - ord('a') + 1] := i;
  end;
  for i := 1 to length(s) do
  begin
    p := b[ord(s[i]) - ord('a') + 1];
    if (a1 + a2 = 0) then t := p;
    if (p = t) and (p <> 0) then
      if s[i] = a[p][1] then inc(a1) else inc(a2)
    else
    begin
      if a1 > a2 then
        a1 := a2;
      kol := kol + a1;
      a1 := 0;
      a2 := 0;
      if p <> 0 then
        if s[i] = a[p][1] then inc(a1) else inc(a2);
    end;
    t := p;
  end;
  if a1 > a2 then
    a1 := a2;
  kol := kol + a1;
  write(kol);
end.