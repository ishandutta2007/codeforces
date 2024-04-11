program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    a, b, c, d : integer;
  end;

var
  n, num, i, j : integer;
  fl : boolean;
  p : array[0..101] of tp;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(p[i].a, p[i].b, p[i].c, p[i].d);
  num := 0;
  for i := 1 to n do begin
    fl := true;
    for j := 1 to n do
      if (p[i].a < p[j].a) and (p[i].b < p[j].b) and (p[i].c < p[j].c) then begin
        fl := false;
        break;
      end;
    if (fl) and ((num = 0) or (p[i].d < p[num].d)) then
      num := i;
  end;
  writeln(num);
end.