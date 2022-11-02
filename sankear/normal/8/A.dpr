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
  hx = 200003;

var
  len, lens, lena, lenb, i : integer;
  f1, f2 : boolean;
  ha, hb : int64;
  s, r, a, b : string;
  pow, h : array[0..100001] of int64;
  can : array[0..100001] of boolean;

function solve(var s : string; n : integer) : boolean;
var i : integer;
begin
  result := false;
  for i := 1 to n do
    h[i] := h[i - 1] + pow[i] * ord(s[i]);
  can[n + 1] := false;
  for i := n - lenb + 1 downto 1 do begin
    can[i] := can[i + 1];
    if pow[len - i] * (h[i + lenb - 1] - h[i - 1]) = hb then
      can[i] := true;
  end;
  for i := 1 to n - lena + 1 do
    if (pow[len - i] * (h[i + lena - 1] - h[i - 1]) = ha) and (can[i + lena]) then begin
      result := true;
      break;
    end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  readln(a);
  readln(b);
  lens := length(s);
  lena := length(a);
  lenb := length(b);
  len := max(lens, max(lena, lenb));
  pow[0] := 1;
  for i := 1 to len do
    pow[i] := pow[i - 1] * hx;
  ha := 0;
  for i := 1 to lena do
    ha := ha + pow[i] * ord(a[i]);
  ha := ha * pow[len - 1];
  hb := 0;
  for i := 1 to lenb do
    hb := hb + pow[i] * ord(b[i]);
  hb := hb * pow[len - 1];
  r := '';
  for i := lens downto 1 do
    r := r + s[i];
  f1 := solve(s, lens);
  f2 := solve(r, lens);
  if (not f1) and (not f2) then
    writeln('fantasy');
  if (not f1) and (f2) then
    writeln('backward');
  if (f1) and (not f2) then
    writeln('forward');
  if (f1) and (f2) then
    writeln('both');
end.