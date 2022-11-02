program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = 1000000000;

var
  n, k, i, j, p, res, ans : integer;
  a : array[0..1001] of char;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n);
  for i := 1 to n do
    read(a[i]);
  k := 0;
  for i := 1 to n do
    if a[i] = 'H' then
      inc(k);
  ans := inf;
  for i := 1 to n do begin
    res := 0;
    p := i;
    for j := 1 to k do begin
      if a[p] <> 'H' then
        inc(res);
      inc(p);
      if p > n then
        p := 1;
    end;
    ans := min(ans, res);
  end;
  write(ans);
end.