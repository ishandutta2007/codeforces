program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  s1, s2 : string;
  i : integer;
  a : array[0..255] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s1);
  readln(s2);
  for i := 1 to length(s1) do
    if s1[i] <> ' ' then
      inc(a[ord(s1[i])]);
  for i := 1 to length(s2) do begin
    if s2[i] = ' ' then
      continue;
    if a[ord(s2[i])] = 0 then begin
      write('NO');
      halt(0);
    end;
    dec(a[ord(s2[i])]);
  end;
  write('YES');
end.