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
  n, k, a, ans, i : integer;
  fl : boolean;
  b : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, k);
  for i := 1 to n do begin
    read(a);
    inc(b[a]);
  end;
  ans := 0;
  while true do begin
    fl := false;
    for i := k downto 2 do
      if b[i - 1] > 0 then begin
        dec(b[i - 1]);
        inc(b[i]);
        fl := true;
      end;
    if not fl then
      break;
    inc(ans);
  end;
  writeln(ans);
end.