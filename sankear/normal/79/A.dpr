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
  a, b, step, i : integer;
  fl : boolean;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b);
  step := 1;
  while (a > 0) or (b > 0) do begin
    if step = 1 then begin
      fl := false;
      for i := 2 downto 0 do
        if (a >= i) and (b >= (220 - i * 100) div 10) then begin
          a := a - i;
          b := b - (220 - i * 100) div 10;
          fl := true;
          break;
        end;
      if not fl then
        break;
      step := 2;
      continue;
    end;
    fl := false;
    for i := 22 downto 0 do
      if (b >= i) and ((220 - i * 10) mod 100 = 0) and (a >= (220 - i * 10) div 100) then begin
        a := a - (220 - i * 10) div 100;
        b := b - i;
        fl := true;
        break;
      end;
    if not fl then
      break;
    step := 1;
  end;
  if step = 1 then
    writeln('Hanako')
  else
    writeln('Ciel');
end.