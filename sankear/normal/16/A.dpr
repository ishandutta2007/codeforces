program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxn = 100;
  maxm = 100;

var
  n, m, i, j : integer;
  a : array[1..maxn, 1..maxm] of char;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n, m);
  for i := 1 to n do begin
    for j := 1 to m do
      read(a[i, j]);
    readln;
  end;
  for i := 1 to n do
    for j := 2 to m do
      if a[i, j] <> a[i, 1] then begin
        write('NO');
        halt(0);
      end;
  for i := 2 to n do
    if a[i, 1] = a[i - 1, 1] then begin
      write('NO');
      halt(0);
    end;
  write('YES');
end.