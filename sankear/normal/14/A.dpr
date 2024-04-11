program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxn = 50;
  maxm = 50;
  inf = 2000;

var
  n, m, i, j, x1, x2, y1, y2 : integer;
  c : array[1..maxn, 1..maxm] of char;

begin
  readln(n, m);
  x1 := inf;
  y1 := inf;
  x2 := -inf;
  y2 := -inf;
  for i := 1 to n do begin
    for j := 1 to m do begin
      read(c[i, j]);
      if c[i, j] = '*' then begin
        x1 := min(x1, i);
        y1 := min(y1, j);
        x2 := max(x2, i);
        y2 := max(y2, j);
      end;
    end;
    readln;
  end;
  for i := x1 to x2 do begin
    for j := y1 to y2 do
      write(c[i, j]);
    writeln;
  end;
end.