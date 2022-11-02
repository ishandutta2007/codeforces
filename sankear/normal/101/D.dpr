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
  n, k, a, b, c, i : integer;
  ans : double;
  used : array[0..100001] of boolean;
  num, first, cost, p, sz, len : array[0..100001] of integer;
  go, cnt, next : array[0..200001] of integer;
  t, l : array[0..100001] of int64;

procedure add(a, b, c : integer);
begin
  inc(k);
  go[k] := b;
  cnt[k] := c;
  next[k] := first[a];
  first[a] := k;
end;

function calc(a, b : integer) : int64;
begin
  result := int64(cost[a]) * sz[a] + t[a] + (2 * cost[a] + l[a] + len[a] + cost[b]) * sz[b] + t[b];
end;

function less(a, b : integer) : boolean;
begin
  result := calc(a, b) < calc(b, a);
end;

procedure sort(l, r : integer);
var enum, t, i, j : integer;
begin
  if l >= r then
    exit;
  enum := num[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while less(num[i], enum) do
      inc(i);
    while less(enum, num[j]) do
      dec(j);
    if i <= j then begin
      t := num[i];
      num[i] := num[j];
      num[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(i, r);
  sort(l, j);
end;

procedure dfs(a : integer);
var k, i : integer;
begin
  used[a] := true;
  sz[a] := 1;
  i := first[a];
  while i > 0 do begin
    if not used[go[i]] then begin
      p[go[i]] := a;
      cost[go[i]] := cnt[i];
      dfs(go[i]);
      sz[a] := sz[a] + sz[go[i]];
    end;
    i := next[i];
  end;
  k := 0;
  i := first[a];
  while i > 0 do begin
    if p[go[i]] = a then begin
      inc(k);
      num[k] := go[i];
    end;
    i := next[i];
  end;
  sort(1, k);
  for i := 1 to k do begin
    l[num[i]] := l[num[i]] + l[num[i - 1]] + len[num[i - 1]] + cost[num[i - 1]] + cost[num[i]];
    t[num[i]] := t[num[i]] + (l[num[i - 1]] + len[num[i - 1]] + cost[num[i - 1]] + cost[num[i]]) * sz[num[i]];
    t[a] := t[a] + t[num[i]];
  end;
  l[a] := l[num[k]];
  len[a] := len[num[k]] + cost[num[k]];
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  k := 0;
  for i := 1 to n - 1 do begin
    read(a, b, c);
    add(a, b, c);
    add(b, a, c);
  end;
  dfs(1);
  ans := t[1] / (n - 1);
  writeln(ans:0:18);
end.