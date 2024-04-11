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
  n, sz, k, i, j : integer;
  fl : boolean;
  s, r : string;
  w : array[0..11] of string;
  t, f : array[0..101] of string;

function bad1(var s : string) : boolean;
var i : integer;
begin
  result := false;
  for i := 1 to length(s) do
    if s[i] <> '&' then begin
      result := true;
      exit;
    end;
end;

function bad2(var s : string) : boolean;
var i : integer;
begin
  result := false;
  for i := 1 to length(s) do
    if s[i] <> '*' then begin
      result := true;
      exit;
    end;
end;

function get(s : string) : string;
var i : integer;
r1, r2, r3 : string;
begin
  r1 := '';
  r2 := '';
  r3 := '';
  i := 1;
  while (i <= length(s)) and (not (s[i] in ['a'..'z'])) do begin
    r1 := r1 + s[i];
    inc(i);
  end;
  while (i <= length(s)) and (s[i] in ['a'..'z']) do begin
    r2 := r2 + s[i];
    inc(i);
  end;
  while i <= length(s) do begin
    r3 := r3 + s[i];
    inc(i);
  end;
  if (bad1(r1)) or (bad2(r3)) then begin
    result := 'errtype';
    exit;
  end;
  if r2 = 'errtype' then begin
    result := 'errtype';
    exit;
  end;
  if r2 <> 'void' then begin
    for i := 1 to sz do
      if t[i] = r2 then begin
        s := r1 + f[i] + r3;
        result := get(s);
        exit;
      end;
    result := 'errtype';
    exit;
  end;
  while s[1] = '&' do begin
    if s[length(s)] <> '*' then begin
      result := 'errtype';
      exit;
    end;
    delete(s, 1, 1);
    delete(s, length(s), 1);
  end;
  result := s;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n);
  sz := 0;
  for i := 1 to n do begin
    readln(s);
    s := s + ' ';
    k := 0;
    r := '';
    for j := 1 to length(s) do
      if s[j] = ' ' then begin
        if length(r) > 0 then begin
          inc(k);
          w[k] := r;
          r := '';
        end;
      end
      else
        r := r + s[j];
    if w[1] = 'typedef' then begin
      fl := false;
      for j := 1 to sz do
        if t[j] = w[3] then begin
          f[j] := get(w[2]);
          fl := true;
          break;
        end;
      if not fl then begin
        inc(sz);
        t[sz] := w[3];
        f[sz] := get(w[2]);
      end;
      continue;
    end;
    writeln(get(w[2]));
  end;
end.