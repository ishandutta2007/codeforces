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
  inf = round(1e9);
  tl = 2.9;
  maxop = 100;

type
  tp = record
    s, f, l, r, a : integer;
  end;

var
  n, m, op, ans1, ans2, i, j : integer;
  start : double;
  t : tp;
  act, deg1, deg2 : array[0..7] of integer;
  c : array[0..16] of integer;
  p : array[0..16] of tp;

procedure gen(x : integer);
var res1, res2, i : integer;
begin
  inc(op);
  if op >= maxop then begin
    if (now - start) * 24 * 60 * 60 > tl then begin
      if ans1 = inf then
        writeln('-1 -1')
      else
        writeln(ans1, ' ', ans2);
      halt(0);
    end;
    op := 0;
  end;
  if x > m then begin
    for i := 2 to n - 1 do
      if deg1[i] <> deg2[i] then
        exit;
    if act[n] = 0 then
      exit;
    res1 := 0;
    res2 := 0;
    for i := 1 to m do begin
      if p[i].s = 1 then
        res1 := res1 + c[i];
      if c[i] > 0 then
        res2 := res2 + p[i].a + c[i] * c[i];
    end;
    if res1 = 0 then begin
      for i := 1 to m do
        if p[i].l > 0 then
          exit;
    end;
    if (res1 < ans1) or ((res1 = ans1) and (res2 > ans2)) then begin
      ans1 := res1;
      ans2 := res2;
    end;
    exit;
  end;
  for i := p[x].l to p[x].r do
    if (act[p[x].s] > 0) and (not ((p[x].s > 1) and (x < m) and (p[x + 1].s > p[x].s) and (deg1[p[x].s] <> deg2[p[x].s] + i))) then begin
      c[x] := i;
      inc(act[p[x].f]);
      deg1[p[x].f] := deg1[p[x].f] + i;
      deg2[p[x].s] := deg2[p[x].s] + i;
      gen(x + 1);
      dec(act[p[x].f]);
      deg1[p[x].f] := deg1[p[x].f] - i;
      deg2[p[x].s] := deg2[p[x].s] - i;
    end;
end;

begin
  start := now;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  m := (n * (n - 1)) div 2;
  for i := 1 to m do
    read(p[i].s, p[i].f, p[i].l, p[i].r, p[i].a);
  for i := 1 to m - 1 do
    for j := m downto i + 1 do
      if p[i].s > p[j].s then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  ans1 := inf;
  act[1] := 1;
  op := 0;
  gen(1);
  if ans1 = inf then
    writeln('-1 -1')
  else
    writeln(ans1, ' ', ans2);
end.