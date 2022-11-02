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
  n, m, num, sz, i, j, z : integer;
  fl : boolean;
  s : string;
  used : array[0..101] of integer;

procedure gets(var s : string);
var ch : char;
begin
  s := '';
  read(ch);
  while not (ch in ['a'..'z']) do
    read(ch);
  while ch in ['a'..'z'] do begin
    s := s + ch;
    read(ch);
  end;
end;

function good(a, b : integer) : boolean;
var i : integer;
begin
  result := true;
  for i := a to a + b - 1 do
    if used[i] > 0 then begin
      result := false;
      exit;
    end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  num := 0;
  for i := 1 to n do begin
    gets(s);
    if s = 'alloc' then begin
      read(sz);
      fl := false;
      for j := 1 to m - sz + 1 do
        if good(j, sz) then begin
          inc(num);
          for z := j to j + sz - 1 do
            used[z] := num;
          fl := true;
          break;
        end;
      if fl then begin
        writeln(num);
        continue;
      end;
      writeln('NULL');
      continue;
    end;
    if s = 'erase' then begin
      read(sz);
      if sz <= 0 then begin
        writeln('ILLEGAL_ERASE_ARGUMENT');
        continue;
      end;
      fl := false;
      for j := 1 to m do
        if used[j] = sz then begin
          used[j] := 0;
          fl := true;
        end;
      if not fl then
        writeln('ILLEGAL_ERASE_ARGUMENT');
      continue;
    end;
    for j := 2 to m do begin
      if used[j] = 0 then
        continue;
      z := j;
      while (z > 1) and (used[z - 1] = 0) do begin
        used[z - 1] := used[z];
        used[z] := 0;
        dec(z);
      end;
    end;
  end;
end.