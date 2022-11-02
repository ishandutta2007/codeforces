program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, k, i, j, t, res, ans : integer;
  l : array[0..1001] of integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(l[i]);
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if l[i] > l[j] then begin
        t := l[i];
        l[i] := l[j];
        l[j] := t;
      end;
  k := 1;
  ans := 1;
  res := 1;
  for i := 2 to n do
    if l[i] = l[i - 1] then begin
      inc(res);
      ans := max(ans, res);
    end
    else begin
      inc(k);
      res := 1;
    end;
  write(ans, ' ', k);
end.