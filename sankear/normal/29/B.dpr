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
  op = 10000;

var
  i : integer;
  l, d, v, g, r, t, ll, rr : extended;

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

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(l, d, v, g, r);
  t := d / v;
  for i := 0 to op do begin
    ll := (g + r) * i + g;
    rr := ll + r;
    if more(ll, t) then
      break;
    if (meq(t, ll)) and (leq(t, rr)) then begin
      writeln(rr + (l - d) / v:0:9);
      halt(0);
    end;
  end;
  writeln(l / v:0:9);
end.