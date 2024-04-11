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
  n, m, k, s, t, a, b, i, j, z, h, nv : integer;
  ans : extended;
  c : array[0..1025] of integer;
  d : array[0..1025, 0..1025] of extended;
  sz : array[0..11] of integer;
  r : array[0..11, 0..11] of integer;

function good(a, b : integer) : boolean;
begin
  result := a and (1 shl (b - 1)) > 0;
end;

function add(a, b : integer) : integer;
begin
  result := a xor (1 shl (b - 1));
end;

function calc(a : integer) : integer;
var i : integer;
begin
  result := 0;
  for i := 1 to n do
    if good(a, i) then
      inc(result);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, k);
  for i := 1 to m do begin
    read(a, b);
    inc(sz[a]);
    r[a, sz[a]] := b;
    inc(sz[b]);
    r[b, sz[b]] := a;
  end;
  for i := 1 to n do
    for j := 1 to sz[i] do begin
      a := add(add(0, i), r[i, j]);
      d[a, a] := 1;
    end;
  s := 1 shl n - 1;
  for i := 0 to s do
    c[i] := calc(i);
  for i := 0 to s do begin
    j := i;
    while j > 0 do begin
      if d[i, j] > 0 then begin
        for z := 1 to n do begin
          if not good(i, z) then
            continue;
          if good(j, z) then
            t := 1
          else
            t := 2;
          for h := 1 to sz[z] do begin
            nv := r[z, h];
            if not good(i, nv) then begin
              if t = 1 then begin
                a := add(i, nv);
                b := add(add(j, z), nv);
                d[a, b] := d[a, b] + d[i, j] / c[b];
              end
              else begin
                a := add(i, nv);
                b := add(j, nv);
                d[a, b] := d[a, b] + d[i, j] / c[b];
              end;
            end;
          end;
        end;
      end;
      j := (j - 1) and i;
    end;
  end;
  ans := 0;
  for i := 0 to s do
    if c[i] = k then
      ans := ans + d[s, i];
  writeln(ans:0:0);
end.