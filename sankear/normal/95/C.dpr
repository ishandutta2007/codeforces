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
  inf = round(1e15);

type
  tr = record
    num : integer;
    val : int64;
  end;

var
  n, m, k, maxv, x, y, a, b, c, i, j, z : integer;
  cur : tr;
  used : array[0..1001] of boolean;
  first, t, cost : array[0..1001] of integer;
  go, cnt, next : array[0..2001] of integer;
  f : array[0..1001, 0..1001] of int64;
  d : array[0..1001] of int64;
  rmq : array[0..3001] of tr;

procedure add(a, b, c : integer);
begin
  inc(k);
  go[k] := b;
  cnt[k] := c;
  next[k] := first[a];
  first[a] := k;
end;

function less(var a, b : tr) : boolean;
begin
  result := a.val < b.val;
end;

procedure update(a : integer; b : int64);
begin
  a := a + maxv - 1;
  rmq[a].val := b;
  rmq[a].num := a - maxv + 1;
  while a > 1 do begin
    a := a div 2;
    if less(rmq[a * 2], rmq[a * 2 + 1]) then
      rmq[a] := rmq[a * 2]
    else
      rmq[a] := rmq[a * 2 + 1];
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  //writeln((sizeof(used) + sizeof(first) + sizeof(t) + sizeof(cost) + sizeof(go) + sizeof(cnt) + sizeof(next) + sizeof(f) + sizeof(d) + sizeof(rmq)) div 1024 div 1024);
  read(n, m, x, y);
  k := 0;
  for i := 1 to m do begin
    read(a, b, c);
    add(a, b, c);
    add(b, a, c);
  end;
  for i := 1 to n do
    read(t[i], cost[i]);
  maxv := 1;
  while maxv < n do
    maxv := maxv * 2;
  for i := 1 to n do begin
    for j := 1 to 2 * maxv - 1 do
      rmq[j].val := inf;
    for j := 1 to n do begin
      used[j] := false;
      d[j] := inf;
    end;
    d[i] := 0;
    update(i, 0);
    for j := 1 to n do begin
      cur := rmq[1];
      if cur.val = inf then
        break;
      used[cur.num] := true;
      update(cur.num, inf);
      z := first[cur.num];
      while z > 0 do begin
        if d[go[z]] > cur.val + cnt[z] then begin
          d[go[z]] := cur.val + cnt[z];
          if not used[go[z]] then
            update(go[z], d[go[z]]);
        end;
        z := next[z];
      end;
    end;
    for j := 1 to n do
      if d[j] <= t[i] then
        f[i, j] := cost[i]
      else
        f[i, j] := inf;
  end;
  for i := 1 to n do begin
    used[i] := false;
    d[i] := inf;
  end;
  d[x] := 0;
  for i := 1 to n do begin
    a := 0;
    for j := 1 to n do
      if (not used[j]) and ((a = 0) or (d[j] < d[a])) then
        a := j;
    if a = 0 then
      break;
    used[a] := true;
    for j := 1 to n do
      if d[j] > d[a] + f[a, j] then
        d[j] := d[a] + f[a, j];
  end;
  if d[y] = inf then begin
    writeln(-1);
    halt;
  end;
  writeln(d[y]);
end.