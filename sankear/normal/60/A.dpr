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
  n, m, k, i, j, l, r : integer;
  s, w : string;
  ps : array[0..11] of string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n, m);
  l := 1;
  r := n;
  for i := 1 to m do begin
    readln(s);
    s := s + ' ';
    k := 0;
    w := '';
    for j := 1 to length(s) do
      if s[j] = ' ' then begin
        inc(k);
        ps[k] := w;
        w := '';
      end
      else
        w := w + s[j];
    if ps[3] = 'left' then
      r := min(r, strtoint(ps[5]) - 1)
    else
      l := max(l, strtoint(ps[5]) + 1);
  end;
  if l > r then begin
    writeln(-1);
    halt(0);
  end;
  writeln(r - l + 1);
end.