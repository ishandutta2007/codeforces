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
  n, s, a, b, res, i, j : integer;
  x, y : array[0..24] of integer;
  dist : array[0..24, 0..24] of integer;
  d, p1, p2 : array[0..16777215] of integer;

procedure wrans(a : integer);
var b : integer;
begin
  b := a xor (1 shl (p1[a] - 1));
  if p2[a] > 0 then begin
    b := b xor (1 shl (p2[a] - 1));
    if b > 0 then
      wrans(b);
    write('0 ', p1[a], ' ', p2[a], ' ');
  end
  else begin
    if b > 0 then
      wrans(b);
    write('0 ', p1[a], ' ');
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(x[0], y[0]);
  read(n);
  for i := 1 to n do
    read(x[i], y[i]);
  for i := 0 to n - 1 do
    for j := i + 1 to n do
      dist[i, j] := (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  s := 1 shl n - 1;
  for i := 0 to s do
    d[i] := inf;
  d[0] := 0;
  for i := 1 to s do begin
    a := 0;
    for j := n downto 1 do
      if i and (1 shl (j - 1)) > 0 then begin
        a := j;
        break;
      end;
    b := i xor (1 shl (a - 1));
    res := d[b] + 2 * dist[0, a];
    if res < d[i] then begin
      d[i] := res;
      p1[i] := a;
      p2[i] := 0;
    end;
    for j := 1 to a - 1 do
      if i and (1 shl (j - 1)) > 0 then begin
        res := d[b xor (1 shl (j - 1))] + dist[0, j] + dist[j, a] + dist[0, a];
        if res < d[i] then begin
          d[i] := res;
          p1[i] := j;
          p2[i] := a;
        end;
      end;
  end;
  writeln(d[s]);
  wrans(s);
  writeln(0);
end.