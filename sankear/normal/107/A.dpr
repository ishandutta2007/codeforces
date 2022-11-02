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
  inf = round(1e9);

var
  n, m, k, a, b, c, i, j : integer;
  used : array[0..1001] of boolean;
  sin, sout, first, go, cnt, next, res : array[0..1001] of integer;
  v, u, sz : array[0..1000001] of integer;

procedure add(a, b, c : integer);
begin
  inc(sout[a]);
  inc(sin[b]);
  inc(k);
  go[k] := b;
  cnt[k] := c;
  next[k] := first[a];
  first[a] := k;
end;

procedure dfs(a, b : integer);
var i : integer;
begin
  used[a] := true;
  res[a] := b;
  i := first[a];
  while i > 0 do begin
    if not used[go[i]] then
      dfs(go[i], min(b, cnt[i]));
    i := next[i];
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  k := 0;
  for i := 1 to m do begin
    read(a, b, c);
    add(a, b, c);
  end;
  k := 0;
  for i := 1 to n do
    if (sin[i] = 0) and (sout[i] > 0) then begin
      for j := 1 to n do
        used[j] := false;
      dfs(i, inf);
      for j := 1 to n do
        if (used[j]) and (sout[j] = 0) then begin
          inc(k);
          v[k] := i;
          u[k] := j;
          sz[k] := res[j];
        end;
    end;
  writeln(k);
  for i := 1 to k do
    writeln(v[i], ' ', u[i], ' ', sz[i]);
end.