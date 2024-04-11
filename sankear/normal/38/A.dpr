program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, a, b, i, ans : integer;
  d : array[0..101] of integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n - 1 do
    read(d[i]);
  read(a, b);
  ans := 0;
  for i := a to b - 1 do
    ans := ans + d[i];
  write(ans);
end.