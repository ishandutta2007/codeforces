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
  inf = round(1e18);

type
  tr = record
    a, b, c, num : integer;
  end;

var
  n, k, last, step, i : integer;
  maxans : int64;
  r : array[0..100001] of tr;
  col, sz, nsz, prev, rank, first, used, p, l : array[0..100001] of integer;
  go, next : array[0..200001] of integer;
  ans : array[0..100001] of int64;

function less(var a, b : tr) : boolean;
begin
  result := a.c < b.c;
end;

procedure sort(ll, rr : integer);
var er, t : tr;
i, j : integer;
begin
  if ll >= rr then
    exit;
  er := r[ll + random(rr - ll + 1)];
  i := ll;
  j := rr;
  while i <= j do begin
    while less(r[i], er) do
      inc(i);
    while less(er, r[j]) do
      dec(j);
    if i <= j then begin
      t := r[i];
      r[i] := r[j];
      r[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(i, rr);
  sort(ll, j);
end;

function get(a : integer) : integer;
begin
  if prev[a] <> a then
    prev[a] := get(prev[a]);
  result := prev[a];
end;

procedure merge(a, b : integer);
begin
  if rank[a] = rank[b] then begin
    prev[b] := a;
    inc(rank[a]);
    sz[a] := sz[a] + sz[b];
    exit;
  end;
  if rank[a] < rank[b] then begin
    prev[a] := b;
    sz[b] := sz[b] + sz[a];
    exit;
  end;
  prev[b] := a;
  sz[a] := sz[a] + sz[b];
end;

function f(a : integer) : integer;
begin
  if col[a] = step then begin
    result := first[a];
    exit;
  end;
  col[a] := step;
  result := 0;
end;

procedure add(a, b : integer);
begin
  inc(k);
  go[k] := b;
  next[k] := f(a);
  first[a] := k;
end;

procedure dfs(a, b : integer);
var i : integer;
begin
  used[a] := step;
  p[a] := b;
  nsz[a] := sz[a];
  i := f(a);
  while i > 0 do begin
    if used[go[i]] <> step then begin
      dfs(go[i], b);
      nsz[a] := nsz[a] + nsz[go[i]];
    end;
    i := next[i];
  end;
end;

procedure solve(ll, rr : integer);
var a, b, i : integer;
begin
  inc(step);
  k := 0;
  for i := ll to rr do begin
    a := get(r[i].a);
    b := get(r[i].b);
    add(a, b);
    add(b, a);
  end;
  for i := ll to rr do begin
    a := get(r[i].a);
    if used[a] <> step then
      dfs(a, a);
  end;
  for i := ll to rr do begin
    a := get(r[i].a);
    b := get(r[i].b);
    if nsz[a] > nsz[b] then
      ans[r[i].num] := int64(nsz[p[a]] - nsz[b]) * nsz[b] * 2
    else
      ans[r[i].num] := int64(nsz[p[b]] - nsz[a]) * nsz[a] * 2;
  end;
  for i := ll to rr do
    merge(get(r[i].a), get(r[i].b));
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n - 1 do begin
    read(r[i].a, r[i].b, r[i].c);
    r[i].num := i;
  end;
  sort(1, n - 1);
  for i := 1 to n do begin
    rank[i] := 1;
    prev[i] := i;
    sz[i] := 1;
  end;
  step := 0;
  last := 1;
  for i := 2 to n - 1 do
    if less(r[i - 1], r[i]) then begin
      solve(last, i - 1);
      last := i;
    end;
  solve(last, n - 1);
  maxans := -inf;
  for i := 1 to n - 1 do
    if ans[i] > maxans then begin
      maxans := ans[i];
      k := 1;
      l[1] := i;
    end
    else
      if ans[i] = maxans then begin
        inc(k);
        l[k] := i;
      end;
  writeln(maxans, ' ', k);
  for i := 1 to k - 1 do
    write(l[i], ' ');
  writeln(l[k]);
end.