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
  beps = 1e-12;
  eps = 1e-8;
  inf = 1e9;

var
  n, i : integer;
  k, ans, l, r, mid, sum1, sum2, res : extended;
  a : array[0..10001] of extended;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, k);
  for i := 1 to n do
    read(a[i]);
  ans := 0;
  l := -inf;
  r := inf;
  while r - l > beps do begin
    mid := l + (r - l) / 2;
    sum1 := 0;
    sum2 := 0;
    for i := 1 to n do begin
      sum1 := sum1 + max(a[i] - mid, 0);
      sum2 := sum2 + max(mid - a[i], 0);
    end;
    res := sum1 * (100 - k) / 100 - sum2;
    if abs(res) < eps then begin
      ans := mid;
      l := mid;
    end
    else
      if res > 0 then
        l := mid
      else
        r := mid;
  end;
  writeln(ans:0:9);
end.