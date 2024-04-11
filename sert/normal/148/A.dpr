program C105;

{$APPTYPE CONSOLE}

var s: string;
    m, l, k, d, kol, n, i, j, t, p: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n, m, l, k, d);
  kol := 0;
  for i := 1 to d do
  if (i mod n <> 0) and (i mod m <> 0) and (i mod k <> 0) and (i mod l <> 0) then inc(kol);
  write(d - kol);

end.