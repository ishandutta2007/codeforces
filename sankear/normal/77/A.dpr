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
  inf = round(1e15);

var
  n, i : integer;
  ans1, ans2 : int64;
  s1, s2, s3 : string;
  good : array[0..8, 0..8] of boolean;
  b : array[0..4] of integer;
  t : array[0..8] of integer;
  a, c : array[0..8] of int64;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z', 'A'..'Z']) do
    read(c);
  while c in ['a'..'z', 'A'..'Z'] do begin
    s := s + c;
    read(c);
  end;
end;

function f(var s : string) : integer;
begin
  if s = 'Anka' then begin
    result := 1;
    exit;
  end;
  if s = 'Chapay' then begin
    result := 2;
    exit;
  end;
  if s = 'Cleo' then begin
    result := 3;
    exit;
  end;
  if s = 'Troll' then begin
    result := 4;
    exit;
  end;
  if s = 'Dracul' then begin
    result := 5;
    exit;
  end;
  if s = 'Snowy' then begin
    result := 6;
    exit;
  end;
  result := 7;
end;

procedure gen(x : integer);
var res, i, j : integer;
minc, maxc : int64;
begin
  if x > 7 then begin
    for i := 1 to 3 do
      b[i] := 0;
    for i := 1 to 7 do
      inc(b[t[i]]);
    for i := 1 to 3 do
      if b[i] = 0 then
        exit;
    for i := 1 to 7 do
      c[i] := a[t[i]] div b[t[i]];
    minc := inf;
    maxc := -inf;
    for i := 1 to 7 do begin
      minc := min(minc, c[i]);
      maxc := max(maxc, c[i]);
    end;
    res := 0;
    for i := 1 to 7 do
      for j := 1 to 7 do
        if (i <> j) and (t[i] = t[j]) and (good[i, j]) then
          inc(res);
    if maxc - minc < ans1 then begin
      ans1 := maxc - minc;
      ans2 := res;
    end
    else
      if (maxc - minc = ans1) and (res > ans2) then
        ans2 := res;
    exit;
  end;
  for i := 1 to 3 do begin
    t[x] := i;
    gen(x + 1);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    gets(s1);
    gets(s2);
    gets(s3);
    good[f(s1), f(s3)] := true;
  end;
  for i := 1 to 3 do
    read(a[i]);
  ans1 := inf;
  gen(1);
  writeln(ans1, ' ', ans2);
end.