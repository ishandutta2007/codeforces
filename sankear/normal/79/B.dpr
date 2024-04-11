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
  n, m, k, t, xx, yy, ans, i, j : integer;
  fl : boolean;
  x, y : array[0..1001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, k, t);
  for i := 1 to k do
    read(x[i], y[i]);
  for i := 1 to t do begin
    read(xx, yy);
    fl := false;
    for j := 1 to k do
      if (x[j] = xx) and (y[j] = yy) then begin
        fl := true;
        break;
      end;
    if fl then begin
      writeln('Waste');
      continue;
    end;
    ans := (xx - 1) * m + yy;
    for j := 1 to k do
      if (x[j] < xx) or ((x[j] = xx) and (y[j] < yy)) then
        dec(ans);
    if ans mod 3 = 1 then begin
      writeln('Carrots');
      continue;
    end;
    if ans mod 3 = 2 then begin
      writeln('Kiwis');
      continue;
    end;
    writeln('Grapes');
  end;
end.