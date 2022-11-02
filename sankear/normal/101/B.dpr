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
  mp = round(1e9 + 7);

type
  tp = record
    l, r : integer;
  end;

var
  n, m, ans, maxv, gl, gr, l, r, mid, i : integer;
  p : array[0..100001] of tp;
  d : array[0..100001] of integer;
  rmq : array[0..280001] of integer;

function less(var a, b : tp) : boolean;
begin
  result := a.r < b.r;
end;

procedure sort(l, r : integer);
var ep, t : tp;
i, j : integer;
begin
  if l >= r then
    exit;
  ep := p[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while less(p[i], ep) do
      inc(i);
    while less(ep, p[j]) do
      dec(j);
    if i <= j then begin
      t := p[i];
      p[i] := p[j];
      p[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(i, r);
  sort(l, j);
end;

procedure add(var a : integer; b : integer);
begin
  a := a + b;
  while a >= mp do
    a := a - mp;
end;

procedure update(a, b : integer);
begin
  a := a + maxv - 1;
  rmq[a] := b;
  while a > 1 do begin
    a := a div 2;
    rmq[a] := rmq[a * 2];
    add(rmq[a], rmq[a * 2 + 1]);
  end;
end;

function get(l, r : integer) : integer;
begin
  result := 0;
  l := l + maxv - 1;
  r := r + maxv - 1;
  while l <= r do begin
    if l mod 2 <> 0 then
      add(result, rmq[l]);
    l := (l + 1) div 2;
    if r mod 2 = 0 then
      add(result, rmq[r]);
    r := (r - 1) div 2;
  end;
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to m do
    read(p[i].l, p[i].r);
  sort(1, m);
  maxv := 1;
  while maxv < m do
    maxv := maxv * 2;
  for i := 1 to m do begin
    if p[i].l = 0 then
      add(d[i], 1);
    gl := 0;
    l := 1;
    r := i - 1;
    while l <= r do begin
      mid := (l + r) div 2;
      if p[mid].r >= p[i].l then begin
        gl := mid;
        r := mid - 1;
      end
      else
        l := mid + 1;
    end;
    gr := 0;
    l := 1;
    r := i - 1;
    while l <= r do begin
      mid := (l + r) div 2;
      if p[mid].r < p[i].r then begin
        gr := mid;
        l := mid + 1;
      end
      else
        r := mid - 1;
    end;
    if (gl > 0) and (gr > 0) then
      add(d[i], get(gl, gr));
    update(i, d[i]);
  end;
  ans := 0;
  for i := 1 to m do
    if p[i].r = n then
      add(ans, d[i]);
  writeln(ans);
end.