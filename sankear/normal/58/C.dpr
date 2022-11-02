program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = 1000000000;

type
  td = record
    k, l, r : integer;
  end;

var
  n, cv, ans, i : integer;
  a, b : array[0..100001] of integer;
  d : array[0..100001] of td;

procedure calc(v : integer);
begin
  if v = 0 then
    exit;
  d[v].k := d[d[v].l].k + d[d[v].r].k + 1;
end;

procedure split(v, a : integer; var l, r : integer);
begin
  if v = 0 then begin
    l := 0;
    r := 0;
    exit;
  end;
  if b[v] < a then begin
    l := v;
    split(d[v].r, a, d[v].r, r);
  end
  else begin
    r := v;
    split(d[v].l, a, l, d[v].l);
  end;
  calc(v);
end;

function can(v1, v2 : integer) : boolean;
begin
  result := random(d[v1].k + d[v2].k) < d[v1].k;
end;

function merge(v1, v2 : integer) : integer;
begin
  if v1 = 0 then begin
    result := v2;
    exit;
  end;
  if v2 = 0 then begin
    result := v1;
    exit;
  end;
  if can(v1, v2) then begin
    result := v1;
    d[v1].r := merge(d[v1].r, v2);
  end
  else begin
    result := v2;
    d[v2].l := merge(v1, d[v2].l);
  end;
  calc(result);
end;

procedure add(num : integer);
var l, r : integer;
begin
  d[num].k := 1;
  d[num].l := 0;
  d[num].r := 0;
  split(cv, b[num], l, r);
  cv := merge(l, merge(num, r));
end;

procedure solve(a1 : integer);
var r1, r2, r3, res : integer;
begin
  split(cv, a1, r1, r2);
  split(r2, a1 + 1, r2, r3);
  res := n - 1 - d[r2].k;
  if a[1] <> a1 then
    inc(res);
  ans := min(ans, res);
  cv := merge(r1, merge(r2, r3));
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  randomize;
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 2 to n do
    if i <= (n + 1) div 2 then
      b[i] := a[i] - i + 1
    else
      b[i] := a[i] + i - n;
  cv := 0;
  for i := 2 to n do
    add(i);
  ans := inf;
  for i := 1 to 100000 do
    solve(i);
  writeln(ans);
end.