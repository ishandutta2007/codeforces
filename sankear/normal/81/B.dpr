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
  k, i : integer;
  s, r : string;
  w : array[0..301] of string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  s := s + ' ';
  k := 0;
  r := '';
  for i := 1 to length(s) do begin
    if s[i] in ['0'..'9'] then begin
      if (length(r) > 0) and (not (r[1] in ['0'..'9'])) then begin
        inc(k);
        w[k] := r;
        r := '';
      end;
      r := r + s[i];
      continue;
    end;
    if s[i] = ',' then begin
      if length(r) > 0 then begin
        inc(k);
        w[k] := r;
      end;
      r := ',';
      continue;
    end;
    if s[i] = '.' then begin
      if ((length(r) > 0) and (r[1] <> '.')) or ((length(r) = 3) and (r[1] = '.')) then begin
        inc(k);
        w[k] := r;
        r := '';
      end;
      r := r + '.';
      continue;
    end;
    if length(r) > 0 then begin
      inc(k);
      w[k] := r;
      r := '';
    end;
  end;
  if k = 0 then
    halt;
  write(w[1]);
  if (w[1, 1] = ',') and (k > 1) then
    write(' ');
  for i := 2 to k do begin
    if w[i, 1] in ['0'..'9'] then begin
      if w[i - 1, 1] in ['0'..'9'] then
        write(' ');
      write(w[i]);
      continue;
    end;
    if w[i, 1] = ',' then begin
      write(w[i]);
      if i < k then
        write(' ');
      continue;
    end;
    if w[i - 1, 1] <> ',' then
      write(' ');
    write(w[i]);
  end;
  writeln;
end.