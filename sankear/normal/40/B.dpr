program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, m, x, i, j, ans : integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, m, x);
  ans := 0;
  for i := 1 to n do
    for j := 1 to m do
      if (min(min(i, n - i + 1), min(j, m - j + 1)) = x) and ((i + j) mod 2 = 0) then
        inc(ans);
  writeln(ans);
end.