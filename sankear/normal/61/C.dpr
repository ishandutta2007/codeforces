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
  i, k : integer;
  a, b, ch, pow : int64;
  vals : array [1..13] of int64 = (1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000);
  roms : array [1..13] of string[2] = ('I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M');
  ans : array[0..100001] of int64;
  s, t : string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  readln(t);
  a := 0;
  b := 0;
  k := 1;
  for i := 1 to length(s) do
    if s[i] = ' ' then
      inc(k)
    else begin
      if k = 1 then
        a := a * 10 + ord(s[i]) - ord('0');
      if k = 2 then
        b := b * 10 + ord(s[i]) - ord('0');
    end;
  pow := 1;
  ch := 0;
  for i := length(t) downto 1 do begin
    if t[i] in ['0'..'9'] then
      ch := ch + pow * (ord(t[i]) - ord('0'))
    else
      ch := ch + pow * (ord(t[i]) - ord('A') + 10);
    pow := pow * a;
  end;
  if s[length(s)] = 'R' then begin
    i := 13;
    while ch > 0 do begin
      while vals[i] > ch do
        dec(i);
      ch := ch - vals[i];
      write(roms[i]);
    end;
    writeln;
    halt(0);
  end;
  if ch = 0 then begin
    writeln(0);
    halt(0);
  end;
  k := 0;
  while ch > 0 do begin
    inc(k);
    ans[k] := ch mod b;
    ch := ch div b;
  end;
  for i := k downto 1 do
    if ans[i] < 10 then
      write(ans[i])
    else
      write(chr(ord('A') + ans[i] - 10));
  writeln;
end.