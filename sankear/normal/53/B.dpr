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
  eps = 1e-9;

var
  h, w, pow, l, r, a, b : int64;

function eq(a, b : extended) : boolean;
begin
  result := abs(a - b) < eps;
end;

function less(a, b : extended) : boolean;
begin
  result := (not eq(a, b)) and (a < b);
end;

function more(a, b : extended) : boolean;
begin
  result := (not eq(a, b)) and (a > b);
end;

function leq(a, b : extended) : boolean;
begin
  result := (less(a, b)) or (eq(a, b));
end;

function meq(a, b : extended) : boolean;
begin
  result := (more(a, b)) or (eq(a, b));
end;

function getl(a : extended) : int64;
var l, r : int64;
begin
  l := round(a) - 10;
  r := round(a) + 10;
  while l <= r do begin
    if meq(l, a) then begin
      result := l;
      exit;
    end;
    l := l + 1;
  end;
end;

function getr(a : extended) : int64;
var l, r : int64;
begin
  l := round(a) - 10;
  r := round(a) + 10;
  while r >= l do begin
    if leq(r, a) then begin
      result := r;
      exit;
    end;
    r := r - 1;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(h, w);
  a := 0;
  b := 0;
  pow := 1;
  while pow <= h do begin
    l := getl(pow / 1.25);
    r := min(getr(pow / 0.8), w);
    if (l <= r) and (r >= 1) and ((pow * r > a * b) or ((pow * r = a * b) and (pow > a))) then begin
      a := pow;
      b := r;
    end;
    pow := pow * 2;
  end;
  pow := 1;
  while pow <= w do begin
    l := getl(0.8 * pow);
    r := min(getr(1.25 * pow), h);
    if (l <= r) and (r >= 1) and ((pow * r > a * b) or ((pow * r = a * b) and (r > a))) then begin
      a := r;
      b := pow;
    end;
    pow := pow * 2;
  end;
  writeln(a, ' ', b);
end.