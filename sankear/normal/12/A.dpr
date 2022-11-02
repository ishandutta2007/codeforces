program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i, j : integer;
  c : array[1..3, 1..3] of char;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  for i := 1 to 3 do begin
    for j := 1 to 3 do
      read(c[i, j]);
    readln;
  end;
  if (c[1, 1] = c[3, 3]) and (c[2, 1] = c[2, 3]) and (c[3, 1] = c[1, 3]) and (c[1, 2] = c[3, 2]) then
    write('YES')
  else
    write('NO');
end.