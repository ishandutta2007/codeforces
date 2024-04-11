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
  op = 5000;

type
  ts = array[0..11] of char;
  ta = array[0..11] of integer;

var
  ans, len1, len2, len, maxc, i, j, ost : integer;
  c, d : ta;
  a, b : ts;

function calc(var a : ta; len : integer) : integer;
begin
  result := 0;
  for i := 1 to len do
    result := max(result, a[i]);
end;

procedure gets(var s : ts; var len : integer);
var c : char;
begin
  len := 0;
  read(c);
  while not (c in ['0'..'9']) do
    read(c);
  while c in ['0'..'9'] do begin
    inc(len);
    s[len] := c;
    read(c);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  gets(a, len1);
  gets(b, len2);
  for i := len1 downto 1 do
    c[len1 - i + 1] := ord(a[i]) - ord('0');
  for i := len2 downto 1 do
    d[len2 - i + 1] := ord(b[i]) - ord('0');
  ans := 0;
  maxc := max(calc(c, len1), calc(d, len2));
  for i := maxc + 1 to maxc + op do begin
    ost := 0;
    len := max(len1, len2);
    for j := 1 to len do
      ost := (ost + c[j] + d[j]) div i;
    if ost > 0 then
      inc(len);
    ans := max(ans, len);
  end;
  writeln(ans);
end.