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
  n, len, cur, i, j, z : integer;
  ch : char;
  ss : string;
  s : array[0..200001] of string;
  pow : array[0..21] of integer;
  p : array[0..41] of integer;
  f, d : array[0..200001] of integer;
  b, c : array[0..21, 0..200001] of integer;
  pos : array[0..21, 0..1100001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  //writeln((sizeof(s) + sizeof(pow) + sizeof(p) + sizeof(f) + sizeof(d) + sizeof(minp) + sizeof(b) + sizeof(c) + sizeof(pos)) div 1024 div 1024);
  readln(n);
  for i := 1 to n do
    readln(s[i]);
  {read(n);
  for i := 1 to n do
    for j := 1 to 10 do begin
      read(ch);
      while not (ch in ['0'..'1']) do
        read(ch);
      s[i] := s[i] + ch;
    end;}
  len := length(s[1]);
  pow[0] := 1;
  for i := 1 to len - 1 do
    pow[i] := pow[i - 1] * 2;
  for i := 1 to len do
    for j := 1 to n do
      b[i, j] := b[i - 1, j] + pow[i - 1] * (ord(s[j, len - i + 1]) - ord('0'));
  for i := 1 to len do
    for j := 1 to n do
      c[i, j] := c[i - 1, j] * 2 + ord(s[j, i]) - ord('0');
  for i := 2 to n do begin
    ss := s[i] + '#' + s[i - 1];
    for j := 2 to 2 * len + 1 do begin
      z := p[j - 1];
      while (z > 0) and (ss[z + 1] <> ss[j]) do
        z := p[z];
      p[j] := 0;
      if ss[z + 1] = ss[j] then
        p[j] := z + 1;
    end;
    f[i] := f[i - 1] + len - p[2 * len + 1];
  end;
  for i := 1 to n do begin
    d[i] := len + f[i];
    if i < n then
      d[i] := d[i] + len;
    if i = n then begin
      for j := 1 to n - 1 do
        d[n] := min(d[n], d[j] + f[n] - f[j + 1]);
      continue;
    end;
    for j := 0 to len do begin
      cur := pos[j, c[j, i + 1]];
      if cur > 0 then
        d[i] := min(d[i], d[cur] + f[i] - f[cur + 1] + len - j);
    end;
    for j := 0 to len do
      if (pos[j, b[j, i]] = 0) or (d[i] < d[pos[j, b[j, i]]] + f[i + 1] - f[pos[j, b[j, i]] + 1]) then
        pos[j, b[j, i]] := i;
  end;
  {for i := 1 to n do
    writeln(d[i]);
  writeln;}
  writeln(d[n]);
end.