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
  n, len, i : integer;
  s : string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n);
  for i := 1 to n do begin
    readln(s);
    len := length(s);
    if len <= 10 then
      writeln(s)
    else
      writeln(s[1], len - 2, s[len]);
  end;
end.