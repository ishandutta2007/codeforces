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
  n, k, i : integer;
  f, deg, num, a, b : array[0..100001] of integer;

procedure dfs(v, pv : integer);
begin
  if num[v] <> 0 then begin
    if num[v] = k then
      b[k] := v
    else
      b[k] := pv;
    exit;
  end;
  num[v] := k;
  dfs(f[v], v);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(f[i]);
  for i := 1 to n do
    inc(deg[f[i]]);
  k := 0;
  for i := 1 to n do
    if deg[i] = 0 then begin
      inc(k);
      a[k] := i;
      dfs(i, i);
    end;
  for i := 1 to n do
    if num[i] = 0 then begin
      inc(k);
      a[k] := i;
      dfs(i, i);
    end;
  if (k = 1) and (a[1] = b[1]) then begin
    writeln(0);
    halt(0);
  end;
  writeln(k);
  for i := 1 to k - 1 do
    writeln(b[i], ' ', a[i + 1]);
  writeln(b[k], ' ', a[1]);
end.