program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i, n : integer;
  kol, d, m, l, x1, x2 : int64;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, d, m, l);
  for i := 1 to n do begin
    x1 := (i - 1) * m;
    x2 := (i - 1) * m + l;
    kol := x2 div d + 1;
    if (kol * d > x2) and (kol * d < i * m) then begin
      write(kol * d);
      halt(0);
    end;
  end;
  kol := ((n - 1) * m + l) div d + 1;
  write(kol * d);
end.