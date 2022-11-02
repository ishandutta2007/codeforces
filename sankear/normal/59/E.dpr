program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{$O-,R+,Q+}
{O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = round(1e9);

type
  tp = record
    a, b, c : integer;
  end;
  tq = record
    a, b : integer;
  end;

var
  n, m, k, kr, ans, num, a, b, l, r, i, j : integer;
  cur : tq;
  p : array[0..100001] of tp;
  d, pp : array[0..3001, 0..3001] of integer;
  queue : array[0..9000001] of tq;
  go, next : array[0..40001] of integer;
  first : array[0..3001] of integer;

procedure add(a, b : integer);
begin
  inc(kr);
  go[kr] := b;
  next[kr] := first[a];
  first[a] := kr;
end;

function eq(var a, b : tp) : boolean;
begin
  result := (a.a = b.a) and (a.b = b.b) and (a.c = b.c);
end;

function less(var a, b : tp) : boolean;
begin
  result := (a.a < b.a) or ((a.a = b.a) and (a.b < b.b)) or ((a.a = b.a) and (a.b = b.b) and (a.c < b.c));
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

function find(a, b, c : integer) : boolean;
var l, r, mid : integer;
f : tp;
begin
  result := false;
  f.a := a;
  f.b := b;
  f.c := c;
  l := 1;
  r := k;
  while l <= r do begin
    mid := l + (r - l) div 2;
    if eq(p[mid], f) then begin
      result := true;
      exit;
    end;
    if less(p[mid], f) then
      l := mid + 1
    else
      r := mid - 1;
  end;
end;

procedure wrans(a, b : integer);
begin
  if (a > 1) or (b > 1) then
    wrans(b, pp[a, b]);
  write(a, ' ');
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, k);
  kr := 0;
  for i := 1 to m do begin
    read(a, b);
    add(a, b);
    add(b, a);
  end;
  for i := 1 to k do
    read(p[i].a, p[i].b, p[i].c);
  sort(1, k);
  for i := 1 to n do
    for j := 1 to n do
      d[i, j] := inf;
  d[1, 1] := 0;
  l := 1;
  r := 1;
  queue[1].a := 1;
  queue[1].b := 1;
  while l <= r do begin
    cur := queue[l];
    inc(l);
    i := first[cur.a];
    while i > 0 do begin
      if (not find(cur.b, cur.a, go[i])) and (d[go[i], cur.a] > d[cur.a, cur.b] + 1) then begin
        d[go[i], cur.a] := d[cur.a, cur.b] + 1;
        pp[go[i], cur.a] := cur.b;
        if go[i] = n then begin
          writeln(d[go[i], cur.a]);
          wrans(go[i], cur.a);
          writeln;
          halt(0);
        end;
        inc(r);
        queue[r].a := go[i];
        queue[r].b := cur.a;
      end;
      i := next[i];
    end;
  end;
  writeln(-1);
end.