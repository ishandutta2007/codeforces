program solution;

{$APPTYPE CONSOLE}

type
  te = record
    a, b, c : integer;
  end;

var
  n, m, i, ans, k : integer;
  p, rank, q, prev : array[1..1000] of integer;
  e : array[1..10000] of te;

procedure sort(l, r : integer);
var x, t : te;
i, j : integer;
begin
  x := e[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while e[i].c < x.c do
      inc(i);
    while e[j].c > x.c do
      dec(j);
    if i <= j then begin
      t := e[i];
      e[i] := e[j];
      e[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort(i, r);
  if j > l then
    sort(l, j);
end;

function findset(x : integer) : integer;
begin
  if x <> p[x] then
    p[x] := findset(p[x]);
  result := p[x];
end;

procedure union(x, y : integer);
begin
  x := findset(x);
  y := findset(y);
  if rank[x] > rank[y] then
    p[y] := x
  else
    p[x] := y;
  if rank[x] = rank[y] then
    inc(rank[y]);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do begin
    read(q[i]);
    p[i] := i;
    rank[i] := 0;
  end;
  read(m);
  for i := 1 to m do
    read(e[i].a, e[i].b, e[i].c);
  sort(1, m);
  ans := 0;
  k := 0;
  for i := 1 to m do
    if (findset(e[i].a) <> findset(e[i].b)) and (prev[e[i].b] = 0) then begin
      union(e[i].a, e[i].b);
      prev[e[i].b] := e[i].a;
      inc(k);
      ans := ans + e[i].c;
    end;
  if k <> n - 1 then
    write(-1)
  else
    write(ans);
end.