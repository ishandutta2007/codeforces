program a110;

{$APPTYPE CONSOLE}

var a: array[1..1000] of longint;
    s, k: string;
    r, n, l, p, j, i, m, kol, sumv, sumh, ii, min: longint;
    area: extended;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  readln(s);
  readln(k);
  min := length(k);
  for i := 1 to length(k) do s := '@' + s + '@';
  for i := 1 to length(s) - length(k) + 1 do
  begin
    kol := 0;
    for j := i to i + length(k) - 1 do
      if s[j] <> k[j - i + 1] then inc(kol);
    if kol < min then min := kol;
  end;
  write(min);
end.