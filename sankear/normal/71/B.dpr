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
  n, k, t, sum, i, j, z : integer;
  a : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, k, t);
  for i := 0 to n + 1 do begin
    for j := 1 to i - 1 do
      a[j] := k;
    for j := i + 1 to n do
      a[j] := 0;
    for j := 0 to k do begin
      a[i] := j;
      sum := 0;
      for z := 1 to n do
        sum := sum + a[z];
      if (sum * 100 <= t * n * k) and (t * n * k < (sum + 1) * 100) then begin
        for z := 1 to n do
          write(a[z], ' ');
        writeln;
        halt(0);
      end;
    end;
  end;
end.