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
  n, m, start, i, j, z : integer;
  ch : char;
  w : string;
  s : array[0..101] of string;
  len : array[0..101] of integer;
  bad : array[0..101] of boolean;

function f(c : char) : integer;
begin
  if c in ['a'..'z'] then begin
    result := ord(c) - ord('a') + 1;
    exit;
  end;
  result := ord(c) - ord('A') + 1;
end;

function check(a, b : integer) : boolean;
var i : integer;
begin
  result := true;
  for i := a to a + len[b] - 1 do
    if f(w[i]) <> f(s[b, i - a + 1]) then begin
      result := false;
      exit;
    end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n);
  for i := 1 to n do begin
    readln(s[i]);
    len[i] := length(s[i]);
  end;
  readln(w);
  read(ch);
  m := length(w);
  for i := 1 to m do
    for j := 1 to n do
      if (i + len[j] - 1 <= m) and (check(i, j)) then begin
        for z := i to i + len[j] - 1 do
          bad[z] := true;
      end;
  for i := 1 to m do
    if bad[i] then begin
      if f(w[i]) = f(ch) then begin
        if w[i] in ['a'..'z'] then
          start := ord('a') - 1
        else
          start := ord('A') - 1;
        for j := 1 to 26 do
          if j <> f(w[i]) then begin
            w[i] := chr(start + j);
            break;
          end;
      end
      else begin
        if w[i] in ['a'..'z'] then
          w[i] := chr(ord('a') + f(ch) - 1)
        else
          w[i] := chr(ord('A') + f(ch) - 1);
      end;
    end;
  writeln(w);
end.