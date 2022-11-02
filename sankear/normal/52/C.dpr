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
    l, r : integer;
    a, add : int64;
  end;

var
  n, m, maxv, i, j, k, l, r : integer;
  fl : boolean;
  add : int64;
  s : string;
  a : array[0..200001] of integer;
  rmq : array[0..525001] of tr;

procedure init();
var i : integer;
begin
  maxv := 1;
  while maxv < n do
    maxv := maxv * 2;
  for i := 1 to maxv do begin
    if i <= n then
      rmq[i + maxv - 1].a := a[i]
    else
      rmq[i + maxv - 1].a := inf;
    rmq[i + maxv - 1].add := 0;
    rmq[i + maxv - 1].l := i;
    rmq[i + maxv - 1].r := i;
  end;
  for i := maxv - 1 downto 1 do begin
    rmq[i].a := min(rmq[i * 2].a, rmq[i * 2 + 1].a);
    rmq[i].add := 0;
    rmq[i].l := rmq[i * 2].l;
    rmq[i].r := rmq[i * 2 + 1].r;
  end;
end;

procedure calc(v : integer);
begin
  if v >= maxv then
    exit;
  rmq[v].a := min(rmq[v * 2].a, rmq[v * 2 + 1].a);
end;

procedure push(v : integer);
begin
  rmq[v].a := rmq[v].a + rmq[v].add;
  if v < maxv then begin
    rmq[v * 2].add := rmq[v * 2].add + rmq[v].add;
    rmq[v * 2 + 1].add := rmq[v * 2 + 1].add + rmq[v].add;
  end;
  rmq[v].add := 0;
end;

procedure update(v, l, r : integer; add : int64);
begin
  push(v);
  if (rmq[v].l > r) or (rmq[v].r < l) then
    exit;
  if (rmq[v].l >= l) and (rmq[v].r <= r) then begin
    rmq[v].add := add;
    push(v);
    exit;
  end;
  update(v * 2, l, r, add);
  update(v * 2 + 1, l, r, add);
  calc(v);
end;

function rmin(v, l, r : integer) : int64;
begin
  push(v);
  if (rmq[v].l > r) or (rmq[v].r < l) then begin
    result := inf;
    exit;
  end;
  if (rmq[v].l >= l) and (rmq[v].r <= r) then begin
    result := rmq[v].a;
    exit;
  end;
  result := min(rmin(v * 2, l, r), rmin(v * 2 + 1, l, r));
  calc(v);
end;

procedure domin(l, r : integer);
begin
  if l <= r then
    writeln(rmin(1, l, r))
  else
    writeln(min(rmin(1, l, n), rmin(1, 1, r)));
end;

procedure doupdate(l, r : integer; add : int64);
begin
  if l <= r then
    update(1, l, r, add)
  else begin
    update(1, l, n, add);
    update(1, 1, r, add);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n);
  for i := 1 to n do
    read(a[i]);
  readln;
  init();
  readln(m);
  for i := 1 to m do begin
    read(l, r);
    inc(l);
    inc(r);
    add := inf;
    readln(s);
    while (length(s) > 0) and (s[1] = ' ') do
      delete(s, 1, 1);
    if length(s) > 0 then begin
      if s[1] = '-' then begin
        delete(s, 1, 1);
        add := -strtoint(s);
      end
      else
        add := strtoint(s);
    end;
    if add <> inf then
      doupdate(l, r, add)
    else
      domin(l, r);
  end;
end.