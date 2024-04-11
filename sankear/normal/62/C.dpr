program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  eps = 1e-9;

type
  tp = record
    x, y : extended;
  end;
  tl = record
    a, b, c : extended;
  end;

var
  n, k, i, j : integer;
  ans : extended;
  p : array[0..101, 0..5] of tp;
  l : array[0..301] of tp;

function eq(a, b : extended) : boolean;
begin
  result := abs(a - b) < eps;
end;

function less(a, b : extended) : boolean; overload;
begin
  result := (not eq(a, b)) and (a < b);
end;

function less(var a, b : tp) : boolean; overload;
begin
  result := (less(a.x, b.x)) or ((eq(a.x, b.x)) and (less(a.y, b.y)));
end;

function leq(a, b : extended) : boolean;
begin
  result := (eq(a, b)) or (a < b);
end;

function zn(a : extended) : integer;
begin
  if less(a, 0) then begin
    result := -1;
    exit;
  end;
  if eq(a, 0) then begin
    result := 0;
    exit;
  end;
  result := 1;
end;

function dist(var p1, p2 : tp) : extended; overload;
begin
  result := sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
end;

function dist(var l : tl; x, y : extended) : extended; overload;
begin
  result := l.a * x + l.b * y + l.c;
end;

procedure swap(var a, b : extended); overload;
var c : extended;
begin
  c := a;
  a := b;
  b := c;
end;

procedure swap(var a, b : tp); overload;
var c : tp;
begin
  c := a;
  a := b;
  b := c;
end;

procedure getline(var l : tl; var p1, p2 : tp);
begin
  l.a := p1.y - p2.y;
  l.b := p2.x - p1.x;
  l.c := p1.x * p2.y - p2.x * p1.y;
end;

function inl(var p1, p2 : tp; x, y : extended) : boolean;
var minx, maxx, miny, maxy : extended;
begin
  minx := p1.x;
  maxx := p2.x;
  if less(maxx, minx) then
    swap(minx, maxx);
  miny := p1.y;
  maxy := p2.y;
  if less(maxy, miny) then
    swap(miny, maxy);
  result := (leq(minx, x)) and (leq(x, maxx)) and (leq(miny, y)) and (leq(y, maxy));
end;

function intr(var p1, p2, p3 : tp; x, y : extended) : boolean;
var z1, z2, z3 : integer;
l : tl;
begin
  getline(l, p1, p2);
  z1 := zn(dist(l, x, y));
  if (z1 = 0) and (inl(p1, p2, x, y)) then begin
    result := true;
    exit;
  end;
  getline(l, p2, p3);
  z2 := zn(dist(l, x, y));
  if (z2 = 0) and (inl(p2, p3, x, y)) then begin
    result := true;
    exit;
  end;
  getline(l, p3, p1);
  z3 := zn(dist(l, x, y));
  if (z3 = 0) and (inl(p3, p1, x, y)) then begin
    result := true;
    exit;
  end;
  result := (z1 = z2) and (z1 = z3) and (z2 = z3);
end;

procedure ll(var p1, p2, p3, p4 : tp);
var d, x, y : extended;
l1, l2 : tl;
begin
  getline(l1, p1, p2);
  getline(l2, p3, p4);
  d := l1.a * l2.b - l2.a * l1.b;
  if eq(d, 0) then
    exit;
  x := (l1.b * l2.c - l2.b * l1.c) / d;
  y := (l2.a * l1.c - l1.a * l2.c) / d;
  if (inl(p1, p2, x, y)) and (inl(p3, p4, x, y)) then begin
    inc(k);
    l[k].x := x;
    l[k].y := y;
  end;
end;

function good(x, y : extended; num : integer) : boolean;
var i : integer;
begin
  result := true;
  for i := 1 to n do
    if (i <> num) and (intr(p[i, 1], p[i, 2], p[i, 3], x, y)) then begin
      result := false;
      exit;
    end;
end;

procedure sort(ll, rr : integer);
var el : tp;
i, j : integer;
begin
  if ll >= rr then
    exit;
  el := l[ll + random(rr - ll + 1)];
  i := ll;
  j := rr;
  while i <= j do begin
    while less(l[i], el) do
      inc(i);
    while less(el, l[j]) do
      dec(j);
    if i <= j then begin
      swap(l[i], l[j]);
      inc(i);
      dec(j);
    end;
  end;
  sort(i, rr);
  sort(ll, j);
end;

function solve(var p1, p2 : tp; num : integer) : extended;
var i, j : integer;
begin
  k := 2;
  l[1] := p1;
  l[2] := p2;
  for i := 1 to n do
    if i <> num then begin
      for j := 1 to 3 do
        ll(p1, p2, p[i, j], p[i, j + 1]);
    end;
  sort(1, k);
  result := 0;
  for i := 1 to k - 1 do
    if good((l[i].x + l[i + 1].x) / 2, (l[i].y + l[i + 1].y) / 2, num) then
      result := result + dist(l[i], l[i + 1]);
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    for j := 1 to 3 do
      read(p[i, j].x, p[i, j].y);
    p[i, 4] := p[i, 1];
  end;
  ans := 0;
  for i := 1 to n do
    for j := 1 to 3 do
      ans := ans + solve(p[i, j], p[i, j + 1], i);
  writeln(ans:0:9);
end.