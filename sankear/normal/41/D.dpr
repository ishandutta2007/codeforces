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
  inf = round(1e9);

var
  n, m, k, ans, res, y, i, j : integer;
  d, py, post : array[0..101, 0..101, 0..12] of integer;
  a : array[0..101, 0..101] of integer;

procedure geti(var a : integer);
var c : char;
begin
  read(c);
  while not (c in ['0'..'9']) do
    read(c);
  a := ord(c) - ord('0');
end;

procedure solve(s : integer);
var i, j, z, x, y, ost, res : integer;
begin
  for i := 1 to n do
    for j := 1 to m do
      for z := 0 to k do
        d[i, j, z] := -inf;
  d[n, s, a[n, s] mod (k + 1)] := a[n, s];
  for i := n downto 2 do
    for j := 1 to m do
      for z := 0 to k do begin
        if d[i, j, z] = -inf then
          continue;
        if j > 1 then begin
          x := i - 1;
          y := j - 1;
          ost := (z + a[i - 1, j - 1]) mod (k + 1);
          res := d[i, j, z] + a[i - 1, j - 1];
          if d[x, y, ost] < res then begin
            d[x, y, ost] := res;
            py[x, y, ost] := j;
            post[x, y, ost] := z;
          end;
        end;
        if j < m then begin
          x := i - 1;
          y := j + 1;
          ost := (z + a[i - 1, j + 1]) mod (k + 1);
          res := d[i, j, z] + a[i - 1, j + 1];
          if d[x, y, ost] < res then begin
            d[x, y, ost] := res;
            py[x, y, ost] := j;
            post[x, y, ost] := z;
          end;
        end;
      end;
end;

procedure wrans(x, y, ost : integer);
begin
  if x < n then begin
    wrans(x + 1, py[x, y, ost], post[x, y, ost]);
    if py[x, y, ost] > y then
      write('L')
    else
      write('R');
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, k);
  for i := 1 to n do
    for j := 1 to m do
      geti(a[i, j]);
  ans := -inf;
  y := 0;
  for i := 1 to m do begin
    solve(i);
    res := -inf;
    for j := 1 to m do
      res := max(res, d[1, j, 0]);
    if res > ans then begin
      ans := res;
      y := i;
    end;
  end;
  if ans = -inf then begin
    writeln(-1);
    halt(0);
  end;
  solve(y);
  writeln(ans);
  writeln(y);
  for i := 1 to m do
    if d[1, i, 0] = ans then begin
      wrans(1, i, 0);
      writeln;
      break;
    end;
end.