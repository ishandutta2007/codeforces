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
  n, m, a, b, s, i, j, z : integer;
  ans : int64;
  r : array[0..20, 0..20] of boolean;
  d : array[0..525001, 0..20] of int64;

function good(m, e : integer) : boolean;
begin
  result := m and (1 shl (e - 1)) > 0;
end;

function add(m, e : integer) : integer;
begin
  result := m xor (1 shl (e - 1));
end;

function first(m : integer) : integer;
var i : integer;
begin
  result := 0;
  for i := 1 to n do
    if good(m, i) then begin
      result := i;
      exit;
    end;
end;

function sz(m : integer) : integer;
var i : integer;
begin
  result := 0;
  for i := 1 to n do
    if good(m, i) then
      inc(result);
end;

procedure print(m : integer);
var i : integer;
begin
  for i := 1 to n do
    if good(m, i) then
      write(i, ' ');
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to m do begin
    read(a, b);
    r[a, b] := true;
    r[b, a] := true;
  end;
  s := 1 shl n - 1;
  for i := 1 to n do
    d[add(0, i), i] := 1;
  for i := 1 to s do begin
    a := first(i);
    for j := a to n do
      if good(i, j) then begin
        for z := a to n do
          if (r[j, z]) and (not good(i, z)) then begin
            b := add(i, z);
            d[b, z] := d[b, z] + d[i, j];
          end;
      end;
  end;
  ans := 0;
  for i := 1 to s do begin
    if sz(i) < 3 then
      continue;
    a := first(i);
    for j := a to n do
      if (r[j, a]) and (good(i, j)) then
        ans := ans + d[i, j];
  end;
  ans := ans div 2;
  writeln(ans);
end.