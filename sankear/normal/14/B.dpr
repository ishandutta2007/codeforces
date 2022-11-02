program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  inf = 2000000000;
  maxn = 100;

var
  n, x0, k, ans, i, j : integer;
  l, r : array[1..maxn] of integer;

begin
  read(n, x0);
  for i := 1 to n do
    read(l[i], r[i]);
  ans := inf;
  for i := 0 to 1000 do begin
    k := 0;
    for j := 1 to n do
      if (min(l[j], r[j]) <= i) and (max(l[j], r[j]) >= i) then
        inc(k);
    if k = n then
      ans := min(ans, abs(i - x0));
  end;
  if ans = inf then
    write(-1)
  else
    write(ans);
end.