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
  add = 100;

var
  i : integer;
  x, ans, res, l, r, mid : int64;

function solve(res : int64) : int64;
begin
  result := inf;
  if ((res * (res + 1)) div 2 - x) mod 2 = 0 then
    result := res;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(x);
  x := abs(x);
  res := 0;
  l := 1;
  r := x;
  while l <= r do begin
    mid := l + (r - l) div 2;
    if (mid * (mid + 1)) div 2 >= x then begin
      res := mid;
      r := mid - 1;
    end
    else
      l := mid + 1;
  end;
  ans := inf;
  for i := 0 to add do
    ans := min(ans, solve(res + i));
  writeln(ans);
end.