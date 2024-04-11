program a110;

{$APPTYPE CONSOLE}

var a: array[1..100, 1..100] of longint;
    s: string;
    n, l, p, j, i, m, kol, sumv, sumh, ii: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  kol := 0;
  read(n);
  m := n;
  for i := 1 to n do for j := 1 to m do read(a[i,j]);
  for i := 1 to n do for j := 1 to m do
  begin
    sumv := 0;
    sumh := 0;
    for ii := 1 to n do sumv := sumv + a[ii, j];
    for ii := 1 to m do sumh := sumh + a[i, ii];
    if sumv > sumh then inc(kol);
  end;
  write(kol);
end.