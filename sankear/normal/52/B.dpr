program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, i, j : integer;
  ans : int64;
  a : array[0..1001, 0..1001] of char;
  l, r, d, u : array[0..1001, 0..1001] of integer;

procedure getc(var c : char);
begin
  read(c);
  while not ((c = '.') or (c = '*')) do
    read(c);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to n do
    for j := 1 to m do
      getc(a[i, j]);
  for i := 1 to n do
    for j := 1 to m do begin
      l[i, j] := l[i, j - 1];
      if a[i, j] = '*' then
        inc(l[i, j]);
    end;
  for i := 1 to n do
    for j := m downto 1 do begin
      r[i, j] := r[i, j + 1];
      if a[i, j] = '*' then
        inc(r[i, j]);
    end;
  for i := 1 to n do
    for j := 1 to m do begin
      u[i, j] := u[i - 1, j];
      if a[i, j] = '*' then
        inc(u[i, j]);
    end;
  for i := n downto 1 do
    for j := 1 to m do begin
      d[i, j] := d[i + 1, j];
      if a[i, j] = '*' then
        inc(d[i, j]);
    end;
  ans := 0;
  for i := 1 to n do
    for j := 1 to m do
      if a[i, j] = '*' then
        ans := ans + u[i - 1, j] * r[i, j + 1] + u[i - 1, j] * l[i, j - 1] + d[i + 1, j] * r[i, j + 1] + d[i + 1, j] * l[i, j - 1];
  writeln(ans);
end.