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
  n, k, num, a, b, i : integer;
  c, ans : int64;
  used, can : array[0..100001] of boolean;
  f : array[0..100001] of int64;
  first : array[0..200001] of integer;
  go, next : array[0..200001] of integer;
  cnt : array[0..200001] of int64;

procedure add(a, b : integer; c : int64);
begin
  inc(k);
  go[k] := b;
  cnt[k] := c;
  next[k] := first[a];
  first[a] := k;
end;

procedure dfs1(a : integer; b : int64);
var na, i : integer;
begin
  used[a] := true;
  f[a] := b;
  i := first[a];
  while i > 0 do begin
    na := go[i];
    if not used[na] then
      dfs1(na, b + cnt[i]);
    i := next[i];
  end;
end;

procedure dfs2(a : integer);
var na, i : integer;
begin
  used[a] := true;
  can[a] := false;
  if a = num then
    can[a] := true;
  i := first[a];
  while i > 0 do begin
    na := go[i];
    if not used[na] then begin
      dfs2(na);
      can[a] := can[a] or can[na];
    end;
    i := next[i];
  end;
end;

procedure dfs3(a : integer);
var na, num, i : integer;
begin
  used[a] := true;
  num := 0;
  i := first[a];
  while i > 0 do begin
    na := go[i];
    if not used[na] then begin
      if not can[na] then begin
        ans := ans + cnt[i];
        dfs3(na);
        ans := ans + cnt[i];
      end
      else
        num := i;
    end;
    i := next[i];
  end;
  if num > 0 then begin
    ans := ans + cnt[num];
    dfs3(go[num]);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n - 1 do begin
    read(a, b, c);
    add(a, b, c);
    add(b, a, c);
  end;
  for i := 1 to n do
    used[i] := false;
  dfs1(1, 0);
  num := 0;
  for i := 1 to n do
    if (num = 0) or (f[i] > f[num]) then
      num := i;
  for i := 1 to n do
    used[i] := false;
  dfs2(1);
  ans := 0;
  for i := 1 to n do
    used[i] := false;
  dfs3(1);
  writeln(ans);
end.