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
  inf = round(2e9);

type
  tp = record
    l, r : int64;
    num : integer;
  end;

var
  n, i, j : integer;
  t : tp;
  c, r, k, d : array[0..2001] of integer;
  p : array[0..2001] of tp;
  f, prev, maxf, maxnum, num : array[0..2001, 0..2001] of integer;

procedure sort(a, l, r : integer);
var enum, t, i, j : integer;
begin
  if l >= r then
    exit;
  enum := num[a, l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while p[num[a, i]].r < p[enum].r do
      inc(i);
    while p[enum].r < p[num[a, j]].r do
      dec(j);
    if i <= j then begin
      t := num[a, i];
      num[a, i] := num[a, j];
      num[a, j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(a, i, r);
  sort(a, l, j);
end;

procedure calc(a : integer);
var i, res, l, r, mid : integer;
begin
  k[a] := 0;
  for i := 1 to n do
    if (i <> a) and (p[i].l >= p[a].l) and (p[i].r <= p[a].r) then begin
      inc(k[a]);
      num[a, k[a]] := i;
    end;
  sort(a, 1, k[a]);
  for i := 1 to k[a] do begin
    f[a, i] := d[p[num[a, i]].num];
    res := 0;
    l := 1;
    r := i - 1;
    while l <= r do begin
      mid := l + (r - l) div 2;
      if p[num[a, mid]].r <= p[num[a, i]].l then begin
        res := mid;
        l := mid + 1;
      end
      else
        r := mid - 1;
    end;
    f[a, i] := f[a, i] + maxf[a, res];
    prev[a, i] := maxnum[a, res];
    if maxf[a, i - 1] > f[a, i] then begin
      maxf[a, i] := maxf[a, i - 1];
      maxnum[a, i] := maxnum[a, i - 1];
    end
    else begin
      maxf[a, i] := f[a, i];
      maxnum[a, i] := i;
    end;
  end;
  d[p[a].num] := 1;
  for i := 1 to k[a] do
    d[p[a].num] := max(d[p[a].num], f[a, i] + 1);
end;

procedure wrans(a : integer); forward;

procedure print(a, b : integer);
begin
  if prev[a, b] > 0 then
    print(a, prev[a, b]);
  wrans(num[a, b]);
end;

procedure wrans(a : integer);
begin
  if d[p[a].num] = 1 then begin
    write(p[a].num, ' ');
    exit;
  end;
  print(a, maxnum[a, k[a]]);
  if a <> n then
    write(p[a].num, ' ');
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(c[i], r[i]);
  inc(n);
  c[n] := 0;
  r[n] := inf;
  for i := 1 to n do begin
    p[i].l := c[i] - r[i];
    p[i].r := c[i] + r[i];
    p[i].num := i;
  end;
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if p[i].r - p[i].l > p[j].r - p[j].l then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  for i := 1 to n do
    calc(i);
  writeln(d[n] - 1);
  wrans(n);
end.