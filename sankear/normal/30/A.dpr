program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  eps = 0.000000001;

var
  a, b, n, x : extended;
  i : integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(a, b, n);
  for i := -1000 to 1000 do begin
    x := a * power(i, n);
    if abs(x - b) < eps then begin
      write(i);
      halt(0);
    end;
  end;
  write('No solution');
end.