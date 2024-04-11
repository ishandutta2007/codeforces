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
  n, k, ans, sum, i, j : integer;
  s : string;
  used : array[0..27] of boolean;
  a, b : array[0..27] of integer;

procedure swap(var a, b : integer);
var c : integer;
begin
  c := a;
  a := b;
  b := c;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  read(k);
  n := length(s);
  if k >= n then begin
    writeln(0);
    writeln;
    halt;
  end;
  for i := 1 to n do
    inc(a[ord(s[i]) - ord('a') + 1]);
  for i := 1 to 26 do
    b[i] := i;
  for i := 1 to 25 do
    for j := 26 downto i + 1 do
      if a[i] < a[j] then begin
        swap(a[i], a[j]);
        swap(b[i], b[j]);
      end;
  sum := 0;
  for i := 1 to 26 do begin
    sum := sum + a[i];
    if sum >= n - k then begin
      ans := i;
      break;
    end;
  end;
  for i := 1 to ans do
    used[b[i]] := true;
  writeln(ans);
  for i := 1 to n do
    if used[ord(s[i]) - ord('a') + 1] then
      write(s[i]);
  writeln;
end.