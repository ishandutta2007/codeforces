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
  da = 500000;
  db = 30;

type
  int = -1..1;

var
  a, b, n : integer;
  ans : int;
  used : array[0..da + 1, 0..db + 1] of boolean;
  d : array[0..da + 1, 0..db + 1] of int;

function pow(a : int64; b : integer) : int64;
var c : int64;
begin
  if b = 1 then begin
    result := a;
    exit;
  end;
  if b mod 2 = 0 then begin
    c := pow(a, b div 2);
    result := c * c;
    exit;
  end;
  result := pow(a, b - 1) * a;
end;

function f(ca, cb : integer) : int;
var r1, r2 : int;
begin
  if used[ca - a, cb - b] then begin
    result := d[ca - a, cb - b];
    exit;
  end;
  used[ca - a, cb - b] := true;
  if pow(ca, cb) >= n then begin
    d[ca - a, cb - b] := 1;
    result := 1;
    exit;
  end;
  if (ca - a > da) or (cb - b > db) then begin
    d[ca - a, cb - b] := 0;
    result := 0;
    exit;
  end;
  r1 := f(ca, cb + 1);
  r2 := f(ca + 1, cb);
  if (r1 = -1) and (r2 = -1) then begin
    d[ca - a, cb - b] := 1;
    result := 1;
    exit;
  end;
  if (r1 = -1) and (r2 = 0) then begin
    d[ca - a, cb - b] := 1;
    result := 1;
    exit;
  end;
  if (r1 = -1) and (r2 = 1) then begin
    d[ca - a, cb - b] := 1;
    result := 1;
    exit;
  end;
  if (r1 = 0) and (r2 = -1) then begin
    d[ca - a, cb - b] := 1;
    result := 1;
    exit;
  end;
  if (r1 = 0) and (r2 = 0) then begin
    d[ca - a, cb - b] := 0;
    result := 0;
    exit;
  end;
  if (r1 = 0) and (r2 = 1) then begin
    d[ca - a, cb - b] := 0;
    result := 0;
    exit;
  end;
  if (r1 = 1) and (r2 = -1) then begin
    d[ca - a, cb - b] := 1;
    result := 1;
    exit;
  end;
  if (r1 = 1) and (r2 = 0) then begin
    d[ca - a, cb - b] := 0;
    result := 0;
    exit;
  end;
  if (r1 = 1) and (r2 = 1) then begin
    d[ca - a, cb - b] := -1;
    result := -1;
    exit;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b, n);
  ans := f(a, b);
  if ans = -1 then begin
    writeln('Stas');
    halt(0);
  end;
  if ans = 0 then begin
    writeln('Missing');
    halt(0);
  end;
  writeln('Masha');
end.