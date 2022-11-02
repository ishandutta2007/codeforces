program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    a, b, l, r : integer;
  end;

var
  n, m, k, res, cur, i, j : integer;
  p : array[0..100001] of tp;
  h, b, go, c : array[0..100001] of integer;
  ans : array[0..100001] of int64;
  prev : array[0..21, 0..100001] of integer;

procedure swap(var a, b : integer);
var c : integer;
begin
  c := a;
  a := b;
  b := c;
end;

function getl(fb : integer) : integer;
var l, r, mid : integer;
begin
  result := 0;
  l := 1;
  r := m;
  while l <= r do begin
    mid := (l + r) div 2;
    if b[mid] < fb then begin
      result := mid;
      l := mid + 1;
    end
    else
      r := mid - 1;
  end;
end;

function getr(fb : integer) : integer;
var l, r, mid : integer;
begin
  result := 0;
  l := 1;
  r := m;
  while l <= r do begin
    mid := (l + r) div 2;
    if b[mid] > fb then begin
      result := mid;
      r := mid - 1;
    end
    else
      l := mid + 1;
  end;
end;

procedure dfs1(v, d : integer);
begin
  h[v] := d;
  if p[v].l = 0 then begin
    inc(m);
    b[m] := p[v].b;
    go[m] := v;
    exit;
  end;
  prev[0, p[v].l] := v;
  prev[0, p[v].r] := v;
  dfs1(p[v].l, d + 1);
  dfs1(p[v].r, d + 1);
end;

procedure dfs2(v : integer);
begin
  if p[v].l = 0 then
    exit;
  ans[p[v].l] := ans[v] + b[getr(p[v].b)];
  ans[p[v].r] := ans[v] + b[getl(p[v].b)];
  dfs2(p[v].l);
  dfs2(p[v].r);
end;

procedure sort(l, r : integer);
var eb, i, j : integer;
begin
  if l >= r then
    exit;
  eb := b[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while b[i] < eb do
      inc(i);
    while eb < b[j] do
      dec(j);
    if i <= j then begin
      swap(b[i], b[j]);
      swap(go[i], go[j]);
      inc(i);
      dec(j);
    end;
  end;
  sort(i, r);
  sort(l, j);
end;

function get(a, b : integer) : integer;
var i : integer;
begin
  if h[a] < h[b] then
    swap(a, b);
  for i := 18 downto 0 do
    if (prev[i, a] > 0) and (h[prev[i, a]] >= h[b]) then
      a := prev[i, a];
  if a = b then begin
    result := a;
    exit;
  end;
  for i := 18 downto 0 do
    if prev[i, a] <> prev[i, b] then begin
      a := prev[i, a];
      b := prev[i, b];
    end;
  result := prev[0, a];
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(p[i].a, p[i].b);
  read(k);
  for i := 1 to k do
    read(c[i]);
  for i := 1 to n do
    if p[i].a > 0 then begin
      if p[p[i].a].l = 0 then
        p[p[i].a].l := i
      else
        p[p[i].a].r := i;
    end;
  for i := 1 to n do
    if (p[i].l > 0) and (p[p[i].l].b > p[p[i].r].b) then
      swap(p[i].l, p[i].r);
  m := 0;
  for i := 1 to n do
    if p[i].a = -1 then begin
      dfs1(i, 0);
      dfs2(i);
      break;
    end;
  for i := 1 to 18 do
    for j := 1 to n do
      prev[i, j] := prev[i - 1, prev[i - 1, j]];
  sort(1, m);
  for i := 1 to k do begin
    res := getl(c[i]);
    if res = 0 then begin
      writeln(ans[go[1]] / h[go[1]]:0:18);
      continue;
    end;
    if res = m then begin
      writeln(ans[go[m]] / h[go[m]]:0:18);
      continue;
    end;
    cur := get(go[res], go[res + 1]);
    if p[cur].b > c[i] then
      writeln(ans[go[res]] / h[go[res]]:0:18)
    else
      writeln(ans[go[res + 1]] / h[go[res + 1]]:0:18);
  end;
end.