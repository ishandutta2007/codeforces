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
  n, a, ans, i : integer;
  k : array[0..4] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    read(a);
    inc(k[a]);
  end;
  ans := inf;
  for i := 1 to 3 do
    ans := min(ans, n - k[i]);
  writeln(ans);
end.