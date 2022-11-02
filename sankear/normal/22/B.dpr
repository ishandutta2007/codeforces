program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, m, i, j, x1, x2, y1, y2, ans : integer;
  fl : boolean;
  a : array[1..25, 1..25] of char;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n, m);
  for i := 1 to n do begin
    for j := 1 to m do
      read(a[i, j]);
    readln;
  end;
  ans := 0;
  for x1 := 1 to n do
    for y1 := 1 to m do
      for x2 := x1 to n do
        for y2 := y1 to m do begin
          fl := true;
          for i := x1 to x2 do
            for j := y1 to y2 do
              if a[i, j] = '1' then
                fl := false;
          if (fl) and (2 * (x2 - x1 + 1 + y2 - y1 + 1) > ans) then
            ans := 2 * (x2 - x1 + 1 + y2 - y1 + 1);
        end;
  write(ans);
end.