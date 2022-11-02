program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  inf = 1000000000000000;

type
  tp = record
    x, c : int64;
  end;

var
  n, i, j : integer;
  t : tp;
  sum : int64;
  p : array[0..3001] of tp;
  d : array[0..3001] of int64;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].x, p[i].c);
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if p[i].x > p[j].x then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  for i := n downto 1 do
    d[i] := inf;
  d[n + 1] := 0;
  for i := n downto 1 do begin
    sum := 0;
    for j := i + 1 to n + 1 do begin
      d[i] := min(d[i], p[i].c + d[j] + sum);
      sum := sum + p[j].x - p[i].x;
    end;
  end;
  write(d[1]);
end.