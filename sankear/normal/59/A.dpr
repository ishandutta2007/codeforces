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
  k1, k2, i : integer;
  s : string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  k1 := 0;
  k2 := 0;
  for i := 1 to length(s) do
    if s[i] in ['a'..'z'] then
      inc(k1)
    else
      inc(k2);
  if k1 < k2 then begin
    s := uppercase(s);
    writeln(s);
    halt(0);
  end;
  s := lowercase(s);
  writeln(s);
end.