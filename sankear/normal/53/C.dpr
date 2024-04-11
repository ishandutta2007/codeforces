program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, l, r, t : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  t := 1;
  l := 1;
  r := n;
  while l <= r do
    if t = 1 then begin
      write(l, ' ');
      inc(l);
      t := 2;
    end
    else begin
      write(r, ' ');
      dec(r);
      t := 1;
    end;
  writeln;
end.