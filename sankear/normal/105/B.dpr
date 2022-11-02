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
  n, k, all, i : integer;
  a, ans : double;
  l, b : array[0..11] of integer;

procedure gen(x, y : integer);
var sz, sum, i, j : integer;
res, cur : double;
begin
  if x > n then begin
    res := 0;
    for i := 0 to all do begin
      cur := 1;
      sz := 0;
      sum := 0;
      for j := 1 to n do
        if (i and (1 shl (j - 1))) > 0 then begin
          cur := cur * l[j] / 100;
          inc(sz);
        end
        else begin
          cur := cur * (1 - l[j] / 100);
          sum := sum + b[j];
        end;
      if sz * 2 > n then
        res := res + cur
      else
        res := res + cur * a / (a + sum);
    end;
    ans := max(ans, res);
    exit;
  end;
  for i := 0 to k - y do begin
    if l[x] + 10 * i > 100 then
      break;
    l[x] := l[x] + 10 * i;
    gen(x + 1, y + i);
    l[x] := l[x] - 10 * i;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, k, a);
  for i := 1 to n do
    read(b[i], l[i]);
  all := (1 shl n) - 1;
  ans := 0;
  gen(1, 0);
  writeln(ans:0:18);
end.