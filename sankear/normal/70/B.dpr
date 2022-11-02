program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = round(1e9);

var
  n, k, maxlen, i, j : integer;
  s, w : string;
  ww : array[0..10001] of string;
  len, d : array[0..10001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(maxlen);
  readln(s);
  n := 0;
  k := 0;
  w := '';
  for i := 1 to length(s) do
    if s[i] in ['a'..'z', 'A'..'Z'] then
      w := w + s[i]
    else begin
      if w <> '' then begin
        inc(k);
        ww[k] := w;
        w := '';
      end;
      if s[i] in ['.', '?', '!'] then begin
        inc(n);
        for j := 1 to k do
          len[n] := len[n] + length(ww[j]) + 1;
        k := 0;
      end;
    end;
  d[0] := 0;
  for i := 1 to n do
    d[i] := inf;
  for i := 1 to n do begin
    if len[i] <= maxlen then
      d[i] := min(d[i], d[i - 1] + 1);
    k := len[i];
    for j := i - 1 downto 1 do begin
      k := k + len[j] + 1;
      if k <= maxlen then
        d[i] := min(d[i], d[j - 1] + 1)
      else
        break;
    end;
  end;
  if d[n] = inf then
    writeln('Impossible')
  else
    writeln(d[n]);
end.