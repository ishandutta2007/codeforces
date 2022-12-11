program africand;

{$APPTYPE CONSOLE}

var x, a, b, c, i: longint;
    sa, sb, sc: string;
    code: integer;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');

  read(a);
  read(b);
  c := a + b;
  str(a, sa);
  str(b, sb);
  str(c, sc);
  i := 1;
  while i <= length(sa) do
    if sa[i] = '0' then
        delete(sa, i, 1) else inc(i);
  i := 1;
  while i <= length(sb) do
    if sb[i] = '0' then
        delete(sb, i, 1) else inc(i);
  i := 1;
  while i <= length(sc) do
    if sc[i] = '0' then
        delete(sc, i, 1) else inc(i);

  val(sa, a, code);
  val(sb, b, code);
  val(sc, c, code);

  if a + b = c then write('YES') else write('NO');

end.