program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type
  tp = record
    a, b : integer;
  end;

var
  n, m, k, i, ans : integer;
  p : array[0..1001] of tp;
  d : array[0..1001] of integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, m, k);
  for i := 1 to n do
    read(p[i].a, p[i].b);
  for i := 1 to m do
    d[i] := 2000000000;
  for i := 1 to n do
    d[p[i].a] := min(d[p[i].a], p[i].b);
  ans := 0;
  for i := 1 to m do
    ans := ans + d[i];
  write(min(ans, k));
end.