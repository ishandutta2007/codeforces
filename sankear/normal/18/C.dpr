program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, i, c, ans : integer;
  sum : array[0..100000] of int64;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  sum[0] := 0;
  for i := 1 to n do begin
    read(c);
    sum[i] := sum[i - 1] + c;
  end;
  ans := 0;
  for i := 1 to n - 1 do
    if sum[i] = sum[n] - sum[i] then
      inc(ans);
  write(ans);
end.