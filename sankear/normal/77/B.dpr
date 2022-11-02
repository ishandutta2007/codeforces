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
  eps = 1e-7;

var
  t, i : integer;
  a, b, all, x, cur, ans : double;

function eq(a, b : double) : boolean;
begin
  result := abs(a - b) < eps;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(t);
  for i := 1 to t do begin
    read(a, b);
    if (eq(a, 0)) and (eq(b, 0)) then begin
      writeln(1.0:0:18);
      continue;
    end;
    if (eq(a, 0)) and (not eq(b, 0)) then begin
      writeln(0.5:0:18);
      continue;
    end;
    if (not eq(a, 0)) and (eq(b, 0)) then begin
      writeln(1.0:0:18);
      continue;
    end;
    all := 2 * a * b;
    x := min(a, 4 * b);
    cur := x * x / 8 + x * b + (a - x) * 2 * b;
    ans := cur / all;
    writeln(ans:0:18);
  end;
end.