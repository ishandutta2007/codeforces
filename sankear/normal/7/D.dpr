program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q-}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  hx = round(2e3 + 3);

var
  n, i : integer;
  ans : int64;
  ch : char;
  s : array[0..5000001] of char;
  pow, lh, rh : array[0..5000001] of integer;
  d : array[0..5000001] of integer;

function check(len : integer) : boolean;
var m : integer;
h1, h2 : integer;
begin
  m := len div 2;
  h1 := pow[n - 1] * lh[m];
  h2 := pow[len - 1] * (rh[len - m + 1] - rh[len + 1]);
  result := h1 = h2;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  //writeln((sizeof(pow) + sizeof(lh) + sizeof(rh) + sizeof(d)) div 1024 div 1024);
  n := 0;
  read(ch);
  while ch in ['a'..'z', 'A'..'Z', '0'..'9'] do begin
    inc(n);
    s[n] := ch;
    read(ch);
  end;
  pow[0] := 1;
  for i := 1 to n do
    pow[i] := pow[i - 1] * hx;
  for i := 1 to n do
    lh[i] := lh[i - 1] + pow[i] * ord(s[i]);
  for i := n downto 1 do
    rh[i] := rh[i + 1] + pow[n - i + 1] * ord(s[i]);
  for i := 1 to n do
    if check(i) then
      d[i] := d[i div 2] + 1;
  ans := 0;
  for i := 1 to n do
    ans := ans + d[i];
  writeln(ans);
end.