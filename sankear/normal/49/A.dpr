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
  i : integer;
  c : char;
  s, r : string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  for i := length(s) downto 1 do
    if (s[i] in ['a'..'z']) or (s[i] in ['A'..'Z']) then begin
      r := lowercase(s[i]);
      c := r[1];
      if (c = 'a') or (c = 'e') or (c = 'i') or (c = 'o') or (c = 'u') or (c = 'y') then
        writeln('YES')
      else
        writeln('NO');
      break;
    end;
end.