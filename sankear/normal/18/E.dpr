program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, m, a, b, i, j, c1, c2, c3, c4, ans, res : integer;
  c : array[1..500, 1..500] of char;
  d, p1, p2 : array[0..500, 1..26, 1..26] of integer;

procedure wrans(x, y, z : integer);
var i : integer;
begin
  if x > 1 then
    wrans(x - 1, p1[x, y, z], p2[x, y, z]);
  for i := 1 to m do
    if i mod 2 = 0 then
      write(chr(ord('a') + z - 1))
    else
      write(chr(ord('a') + y - 1));
  writeln;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n, m);
  for i := 1 to n do begin
    for j := 1 to m do
      read(c[i, j]);
    readln;
  end;
  for i := 0 to 500 do
    for c1 := 1 to 26 do
      for c2 := 1 to 26 do
        d[i, c1, c2] := 2000000000;
  for i := 1 to n do
    for c1 := 1 to 26 do
      for c2 := 1 to 26 do
        if c1 <> c2 then begin
          d[i, c1, c2] := 0;
          j := 1;
          while j <= m do begin
            if ord(c[i, j]) - ord('a') + 1 <> c1 then
              inc(d[i, c1, c2]);
            j := j + 2;
          end;
          j := 2;
          while j <= m do begin
            if ord(c[i, j]) - ord('a') + 1 <> c2 then
              inc(d[i, c1, c2]);
            j := j + 2;
          end;
          if i > 1 then begin
            res := 2000000000;
            for c3 := 1 to 26 do
              for c4 := 1 to 26 do
                if (c1 <> c3) and (c2 <> c4) and (d[i - 1, c3, c4] < res) then begin
                  res := d[i - 1, c3, c4];
                  p1[i, c1, c2] := c3;
                  p2[i, c1, c2] := c4;
                end;
            d[i, c1, c2] := d[i, c1, c2] + res;
          end;
        end;
  ans := 2000000000;
  for i := 1 to 26 do
    for j := 1 to 26 do
      if d[n, i, j] < ans then begin
        ans := d[n, i, j];
        a := i;
        b := j;
      end;
  writeln(d[n, a, b]);
  wrans(n, a, b);
end.