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
  n, m, k, ans, c, i, j, z, h : integer;
  c1, c2 : char;
  s : string;
  cnt : array[0..27, 0..27] of integer;
  d : array[0..101, 0..27, 0..101] of integer;

function f(c : char) : integer;
begin
  result := ord(c) - ord('a') + 1;
end;

procedure getc(var c : char);
begin
  read(c);
  while not (c in ['a'..'z']) do
    read(c);
end;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z']) do
    read(c);
  while c in ['a'..'z'] do begin
    s := s + c;
    read(c);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  gets(s);
  n := length(s);
  read(k, m);
  for i := 1 to m do begin
    getc(c1);
    getc(c2);
    read(c);
    cnt[f(c1), f(c2)] := c;
  end;
  for i := 1 to n do
    for j := 1 to 26 do
      for z := 0 to k do
        d[i, j, z] := -inf;
  d[1, f(s[1]), 0] := 0;
  for i := 1 to 26 do
    if i <> f(s[1]) then
      d[1, i, 1] := 0;
  for i := 1 to n - 1 do
    for j := 1 to 26 do
      for z := 0 to k do
        for h := 1 to 26 do
          if h = f(s[i + 1]) then begin
            d[i + 1, h, z] := max(d[i + 1, h, z], d[i, j, z] + cnt[j, h]);
          end
          else begin
            if z < k then
              d[i + 1, h, z + 1] := max(d[i + 1, h, z + 1], d[i, j, z] + cnt[j, h]);
          end;
  ans := -inf;
  for i := 1 to 26 do
    for j := 0 to k do
      ans := max(ans, d[n, i, j]);
  writeln(ans);
end.