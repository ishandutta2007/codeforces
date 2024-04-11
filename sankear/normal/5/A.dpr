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
  n, k, pos, sz, ans, i, j : integer;
  fl : boolean;
  w : string;
  s, name : array[0..101] of string;
  act : array[0..101] of boolean;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  n := 0;
  while not eof do begin
    inc(n);
    readln(s[n]);
  end;
  k := 0;
  for i := 1 to n do
    if s[i, 1] = '+' then begin
      w := s[i];
      delete(w, 1, 1);
      fl := true;
      for j := 1 to k do
        if name[j] = w then begin
          fl := false;
          break;
        end;
      if fl then begin
        inc(k);
        name[k] := w;
      end;
    end;
  ans := 0;
  for i := 1 to n do begin
    if s[i, 1] = '+' then begin
      w := s[i];
      delete(w, 1, 1);
      for j := 1 to k do
        if name[j] = w then begin
          act[j] := true;
          break;
        end;
      continue;
    end;
    if s[i, 1] = '-' then begin
      w := s[i];
      delete(w, 1, 1);
      for j := 1 to k do
        if name[j] = w then begin
          act[j] := false;
          break;
        end;
      continue;
    end;
    pos := 1;
    while s[i, pos] <> ':' do
      inc(pos);
    sz := 0;
    for j := 1 to k do
      if act[j] then
        inc(sz);
    ans := ans + sz * (length(s[i]) - pos);
  end;
  writeln(ans);
end.