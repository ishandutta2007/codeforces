program solution;

{$APPTYPE CONSOLE}
{$O-}

uses
  SysUtils,
  Math;

const
  x = 200003;

type
  tp = array[1..50] of integer;

var
  t, k0, k, i, j, z, l, r, sr, res : integer;
  n : array[1..20] of integer;
  w : array[1..1000] of string;
  s : array[1..20, 1..50] of string;
  h0, h : array[1..1000] of int64;
  hs : int64;
  b, num, num0 : array[1..1000] of integer;
  p : array[1..1000] of tp;

procedure swaptp(var a, b : tp);
var c : tp;
begin
  c := a;
  a := b;
  b := c;
end;

procedure swap64(var a, b : int64);
var c : int64;
begin
  c := a;
  a := b;
  b := c;
end;

procedure swap(var a, b : integer);
var c : integer;
begin
  c := a;
  a := b;
  b := c;
end;

procedure sort1(l, r : integer);
var x : int64;
i, j : integer;
begin
  x := h0[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while h0[i] < x do
      inc(i);
    while h0[j] > x do
      dec(j);
    if i <= j then begin
      swap64(h0[i], h0[j]);
      swap(num0[i], num0[j]);
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort1(i, r);
  if j > l then
    sort1(l, j);
end;

function cmp(pos : integer; var a, b : tp) : boolean;
var i : integer;
begin
  i := pos;
  while (i <= 50) and (a[i] = b[i]) do
    inc(i);
  result := (i <= 50) and (a[i] > b[i]);
end;

procedure sort2(l, r : integer);
var xp : tp;
nm, x, i, j : integer;
begin
  nm := l + random(r - l + 1);
  x := b[nm];
  xp := p[nm];
  i := l;
  j := r;
  while i <= j do begin
    while (b[i] > x) or ((b[i] = x) and (cmp(1, p[i], xp))) do
      inc(i);
    while (x > b[j]) or ((x = b[j]) and (cmp(1, xp, p[j]))) do
      dec(j);
    if i <= j then begin
      swap64(h[i], h[j]);
      swap(num[i], num[j]);
      swap(b[i], b[j]);
      swaptp(p[i], p[j]);
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort2(i, r);
  if j > l then
    sort2(l, j);
end;

procedure sort3(l, r : integer);
var xp : tp;
nm, x, i, j : integer;
begin
  nm := l + random(r - l + 1);
  x := b[nm];
  xp := p[nm];
  i := l;
  j := r;
  while i <= j do begin
    while (p[i, 1] > xp[1]) or ((p[i, 1] = xp[1]) and (b[i] > x)) or ((p[i, 1] = xp[1]) and (b[i] = x) and (cmp(2, p[i], xp))) do
      inc(i);
    while (xp[1] > p[j, 1]) or ((xp[1] = p[j, 1]) and (x > b[j])) or ((xp[1] = p[j, 1]) and (x = b[j]) and (cmp(2, xp, p[j]))) do
      dec(j);
    if i <= j then begin
      swap64(h[i], h[j]);
      swap(num[i], num[j]);
      swap(b[i], b[j]);
      swaptp(p[i], p[j]);
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort3(i, r);
  if j > l then
    sort3(l, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  randomize;
  readln(t);
  k0 := 0;
  for i := 1 to t do begin
    readln(n[i]);
    for j := 1 to n[i] do begin
      readln(s[i, j]);
      inc(k0);
      w[k0] := s[i, j];
      h0[k0] := 0;
      num0[k0] := k0;
      for z := 1 to length(s[i, j]) do
        h0[k0] := h0[k0] * x + ord(s[i, j, z]);
    end;
  end;
  sort1(1, k0);
  k := 1;
  h[1] := h0[1];
  num[1] := num0[1];
  for i := 2 to k0 do
    if h0[i] <> h0[i - 1] then begin
      inc(k);
      h[k] := h0[i];
      num[k] := num0[i];
    end;
  for i := 1 to t do
    for j := 1 to n[i] do begin
      hs := 0;
      for z := 1 to length(s[i, j]) do
        hs := hs * x + ord(s[i, j, z]);
      l := 1;
      r := k;
      res := 0;
      while l <= r do begin
        sr := (l + r) div 2;
        if h[sr] = hs then begin
          res := sr;
          break;
        end
        else
          if h[sr] < hs then
            l := sr + 1
          else
            r := sr - 1;
      end;
      if j = 1 then
        b[res] := b[res] + 25;
      if j = 2 then
        b[res] := b[res] + 18;
      if j = 3 then
        b[res] := b[res] + 15;
      if j = 4 then
        b[res] := b[res] + 12;
      if j = 5 then
        b[res] := b[res] + 10;
      if j = 6 then
        b[res] := b[res] + 8;
      if j = 7 then
        b[res] := b[res] + 6;
      if j = 8 then
        b[res] := b[res] + 4;
      if j = 9 then
        b[res] := b[res] + 2;
      if j = 10 then
        b[res] := b[res] + 1;
      inc(p[res, j]);
    end;
  sort2(1, k);
  writeln(w[num[1]]);
  sort3(1, k);
  writeln(w[num[1]]);
end.