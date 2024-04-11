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
  n, i : integer;
  s : string;
  a, b : array[0..100001] of integer;

procedure gen(x, y : integer);
var aa, bb, i : integer;
begin
  if x > n then begin
    if y <> 0 then
      exit;
    for i := 1 to n do
      write(b[i]);
    writeln;
    halt;
  end;
  if abs(y) > n - x + 1 then
    exit;
  if a[x] <= 4 then begin
    b[x] := 4;
    if b[x] > a[x] then begin
      dec(y);
      if (n - x - y < 0) or ((n - x - y) mod 2 <> 0) then
        exit;
      bb := (n - x - y) div 2;
      aa := y + bb;
      if aa < 0 then
        exit;
      for i := 1 to aa do begin
        inc(x);
        b[x] := 4;
      end;
      for i := 1 to bb do begin
        inc(x);
        b[x] := 7;
      end;
      gen(n + 1, 0);
    end;
    gen(x + 1, y - 1);
  end;
  if a[x] <= 7 then begin
    b[x] := 7;
    if b[x] > a[x] then begin
      inc(y);
      if (n - x - y < 0) or ((n - x - y) mod 2 <> 0) then
        exit;
      bb := (n - x - y) div 2;
      aa := y + bb;
      if aa < 0 then
        exit;
      for i := 1 to aa do begin
        inc(x);
        b[x] := 4;
      end;
      for i := 1 to bb do begin
        inc(x);
        b[x] := 7;
      end;
      gen(n + 1, 0);
    end;
    gen(x + 1, y + 1);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  n := length(s);
  for i := 1 to n do
    a[i] := ord(s[i]) - ord('0');
  gen(1, 0);
  if n mod 2 = 0 then
    n := (n + 2) div 2
  else
    n := (n + 1) div 2;
  for i := 1 to n do
    write(4);
  for i := 1 to n do
    write(7);
  writeln;
end.