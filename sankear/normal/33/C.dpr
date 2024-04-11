program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, i, ans : integer;
  a, lsum, rsum, d : array[0..100001] of integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(a[i]);
  lsum[0] := 0;
  for i := 1 to n do
    lsum[i] := lsum[i - 1] + a[i];
  rsum[n + 1] := 0;
  for i := n downto 1 do
    rsum[i] := rsum[i + 1] + a[i];
  for i := 1 to n do
    d[i] := -2000000000;
  for i := 1 to n do
    d[i] := max(d[i - 1] + a[i], -lsum[i]);
  ans := d[n];
  for i := n downto 1 do
    ans := max(ans, d[i - 1] - rsum[i]);
  write(ans);
end.