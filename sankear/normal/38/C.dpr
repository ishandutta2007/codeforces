program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, l, i, j, k, ans : integer;
  a : array[0..101] of integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, l);
  for i := 1 to n do
    read(a[i]);
  for i := l to 100 do begin
    k := 0;
    for j := 1 to n do
      k := k + a[j] div i;
    ans := max(ans, i * k);
  end;
  write(ans);
end.