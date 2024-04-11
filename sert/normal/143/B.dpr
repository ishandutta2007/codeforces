program C101a;

{$APPTYPE CONSOLE}

var //a: array[1..100000] of longint;
    k, s: string;
    a, b, c, d, r1, r2, c1, c2, d1, d2, ii, jj, n, m, i, j, t, p: longint;
    fail: boolean;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');

  read(s);
  fail := false;
  if s[1] = '-' then
  begin
    delete(s, 1, 1);
    fail := true;
    write('(');
  end;
  write('$');
  i := length(s);
  while (s[i] <> '.') and (i > 1) do
    dec(i);

  if s[i] <> '.' then
  begin
    s := s + '.';
    i := length(s);
  end;

  //delete(s, i + 3, length(s));
  k := '';
  for j := 1 to i - 1 do
  begin
    k := k + s[j];
    if ((i - j - 1) mod 3 = 0) and (j <> i - 1) then
      k := k + ',';
  end;
  write(k);
  write('.');
  if i = length(s) then
    write('00');
  if i = length(s) - 1 then
  begin
    write(s[i + 1], '0');
  end;
  if i < length(s) - 1 then
    write(s[i + 1], s[i + 2]);



  if fail then write(')');
end.