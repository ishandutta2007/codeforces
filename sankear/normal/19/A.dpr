program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  px = 200003;

var
  n, i, j, k, l, r, x, res, g1, g2, p1, p2 : integer;
  h1, h2 : int64;
  s : string;
  name, wname : array[1..50] of string;
  num, p, w, lst : array[1..50] of integer;
  h : array[1..50] of int64;

procedure sort1(l, r : integer);
var x, t : int64;
i, j : integer;
begin
  x := h[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while h[i] < x do
      inc(i);
    while h[j] > x do
      dec(j);
    if i <= j then begin
      t := h[i];
      h[i] := h[j];
      h[j] := t;
      t := num[i];
      num[i] := num[j];
      num[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort1(i, r);
  if j > l then
    sort1(l, j);
end;

procedure sort2(l, r : integer);
var nm, xp, xw, xlst, t, i, j : integer;
begin
  nm := l + random(r - l + 1);
  xp := p[nm];
  xw := w[nm];
  xlst := lst[nm];
  i := l;
  j := r;
  while i <= j do begin
    while (p[i] > xp) or ((p[i] = xp) and (w[i] - lst[i] > xw - xlst)) or ((p[i] = xp) and (w[i] - lst[i] = xw - xlst) and (w[i] > xw)) do
      inc(i);
    while (p[j] < xp) or ((p[j] = xp) and (w[j] - lst[j] < xw - xlst)) or ((p[j] = xp) and (w[j] - lst[j] = xw - xlst) and (w[j] < xw)) do
      dec(j);
    if i <= j then begin
      t := p[i];
      p[i] := p[j];
      p[j] := t;
      t := w[i];
      w[i] := w[j];
      w[j] := t;
      t := lst[i];
      lst[i] := lst[j];
      lst[j] := t;
      t := num[i];
      num[i] := num[j];
      num[j] := t;
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
var x, t : string;
i, j : integer;
begin
  x := wname[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while wname[i] < x do
      inc(i);
    while wname[j] > x do
      dec(j);
    if i <= j then begin
      t := wname[i];
      wname[i] := wname[j];
      wname[j] := t;
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
  readln(n);
  for i := 1 to n do begin
    readln(name[i]);
    num[i] := i;
    h[i] := 0;
    for j := 1 to length(name[i]) do
      h[i] := h[i] * px + ord(name[i, j]);
  end;
  sort1(1, n);
  for i := 1 to n * (n - 1) div 2 do begin
    readln(s);
    k := 1;
    h1 := 0;
    h2 := 0;
    g1 := 0;
    g2 := 0;
    for j := 1 to length(s) do
      if (s[j] = '-') or (s[j] = ':') or (s[j] = ' ') then
        inc(k)
      else begin
        if k = 1 then
          h1 := h1 * px + ord(s[j]);
        if k = 2 then
          h2 := h2 * px + ord(s[j]);
        if k = 3 then
          g1 := g1 * 10 + ord(s[j]) - ord('0');
        if k = 4 then
          g2 := g2 * 10 + ord(s[j]) - ord('0');
      end;
    if g1 > g2 then begin
      p1 := 3;
      p2 := 0;
    end
    else
      if g1 = g2 then begin
        p1 := 1;
        p2 := 1;
      end
      else begin
        p1 := 0;
        p2 := 3;
      end;
    l := 1;
    r := n;
    while r >= l do begin
      x := (l + r) div 2;
      if h[x] = h1 then begin
        res := x;
        break;
      end
      else
        if h[x] < h1 then
          l := x + 1
        else
          r := x - 1;
    end;
    p[res] := p[res] + p1;
    w[res] := w[res] + g1;
    lst[res] := lst[res] + g2;
    l := 1;
    r := n;
    while r >= l do begin
      x := (l + r) div 2;
      if h[x] = h2 then begin
        res := x;
        break;
      end
      else
        if h[x] < h2 then
          l := x + 1
        else
          r := x - 1;
    end;
    p[res] := p[res] + p2;
    w[res] := w[res] + g2;
    lst[res] := lst[res] + g1;
  end;
  sort2(1, n);
  for i := 1 to n div 2 do
    wname[i] := name[num[i]];
  sort3(1, n div 2);
  for i := 1 to n div 2 do
    writeln(wname[i]);
end.