program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  sz = 100;

var
  n, m, mp, k, a, b, r, c, res, i, j, ii, jj : integer;
  x, y, d : array[0..20001] of integer;
  row : array[0..202, 0..20001] of integer;
  col : array[0..20001, 0..202] of integer;
  f, p : array[0..101, 0..101] of integer;
  s : array[0..40001] of char;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, mp);
  dec(n);
  dec(m);
  for i := 0 to n do begin
    read(x[i]);
    x[i] := x[i] mod mp;
  end;
  for i := 0 to m do begin
    read(y[i]);
    y[i] := y[i] mod mp;
  end;
  for i := 0 to m do begin
    if i > 0 then
      d[i] := d[i - 1];
    res := x[0] + y[i];
    if res >= mp then
      res := res - mp;
    d[i] := d[i] + res;
  end;
  for i := 0 to m do
    row[0, i] := d[i];
  i := 0;
  while i <= m do begin
    col[0, i div sz] := d[i];
    i := i + sz;
  end;
  for i := 1 to n do begin
    for j := 0 to m do begin
      if (j > 0) and (d[j - 1] > d[j]) then
        d[j] := d[j - 1];
      res := x[i] + y[j];
      if res >= mp then
        res := res - mp;
      d[j] := d[j] + res;
    end;
    if i mod sz = 0 then begin
      a := i div sz;
      for j := 0 to m do
        row[a, j] := d[j];
    end;
    j := 0;
    while j <= m do begin
      col[i, j div sz] := d[j];
      j := j + sz;
    end;
  end;
  k := 0;
  i := n;
  j := m;
  while (i > 0) and (j > 0) do begin
    r := (i - 1) div sz;
    c := (j - 1) div sz;
    a := r * sz;
    b := c * sz;
    for ii := 0 to j - b do
      f[0, ii] := row[r, b + ii];
    for ii := 0 to i - a do
      f[ii, 0] := col[a + ii, c];
    for ii := 1 to i - a do
      for jj := 1 to j - b do begin
        f[ii, jj] := f[ii, jj - 1];
        p[ii, jj] := 1;
        if f[ii - 1, jj] > f[ii, jj] then begin
          f[ii, jj] := f[ii - 1, jj];
          p[ii, jj] := 2;
        end;
        res := x[a + ii] + y[b + jj];
        if res >= mp then
          res := res - mp;
        f[ii, jj] := f[ii, jj] + res;
      end;
    ii := i - a;
    jj := j - b;
    while (ii > 0) and (jj > 0) do begin
      if p[ii, jj] = 1 then begin
        inc(k);
        s[k] := 'S';
        dec(jj);
        continue;
      end;
      inc(k);
      s[k] := 'C';
      dec(ii);
    end;
    i := a + ii;
    j := b + jj;
  end;
  while i > 0 do begin
    inc(k);
    s[k] := 'C';
    dec(i);
  end;
  while j > 0 do begin
    inc(k);
    s[k] := 'S';
    dec(j);
  end;
  writeln(d[m]);
  for i := k downto 1 do
    write(s[i]);
  writeln;
end.