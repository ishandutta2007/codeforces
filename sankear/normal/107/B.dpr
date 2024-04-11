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
  n, m, h, sum, i : integer;
  ans : double;
  s : array[0..1001] of integer;

function calc(n, m, k : integer) : double;
begin
  if k = 0 then begin
    result := 1;
    exit;
  end;
  result := calc(n - 1, m, k - 1) * n / (n + m);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, h);
  for i := 1 to m do
    read(s[i]);
  dec(s[h]);
  dec(n);
  sum := 0;
  for i := 1 to m do
    sum := sum + s[i];
  if sum < n then begin
    writeln(-1.0:0:18);
    halt;
  end;
  if sum - s[h] < n then begin
    writeln(1.0:0:18);
    halt;
  end;
  ans := 1 - calc(sum - s[h], s[h], n);
  writeln(ans:0:18);
end.