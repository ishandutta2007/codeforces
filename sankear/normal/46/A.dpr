program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, p, i : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  p := 1;
  for i := 1 to n - 1 do begin
    p := p + i;
    if p > n then
      p := p - n;
    write(p, ' ');
  end;
end.