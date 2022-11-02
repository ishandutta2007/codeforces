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
  n, i, j : integer;
  fl : boolean;
  ans, s, w : string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  readln(n);
  ans := '';
  for i := 1 to 101 do
    ans := ans + 'z';
  for i := 1 to n do begin
    readln(w);
    if length(w) < length(s) then
      continue;
    fl := true;
    for j := 1 to length(s) do
      if s[j] <> w[j] then begin
        fl := false;
        break;
      end;
    if (fl) and (w < ans) then
      ans := w;
  end;
  if length(ans) > 100 then
    writeln(s)
  else
    writeln(ans);
end.