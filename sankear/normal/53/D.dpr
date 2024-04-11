program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{$O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, k, t, p, i, j : integer;
  a, b : array[0..301] of integer;
  v, u : array[0..1000001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    read(b[i]);
  k := 0;
  for i := 1 to n do
    if b[i] <> a[i] then begin
      for j := i + 1 to n do
        if b[j] = a[i] then begin
          p := j;
          break;
        end;
      while p > i do begin
        t := b[p - 1];
        b[p - 1] := b[p];
        b[p] := t;
        inc(k);
        v[k] := p - 1;
        u[k] := p;
        dec(p);
      end;
    end;
  writeln(k);
  for i := 1 to k do
    writeln(v[i], ' ', u[i]);
end.