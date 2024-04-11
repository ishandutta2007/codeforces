program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  inf = 2000000000;

type
  tp = record
    x, y : integer;
  end;
  tv = record
    u : array of integer;
    k : integer;
  end;

var
  n, m, k, i, j, z, ans, res, l, r, cur : integer;
  p : array[0..5] of tp;
  col : array[0..51, 0..51] of integer;
  c : array[0..51, 0..51] of char;
  v : array[0..2501] of tv;
  prev, queue, d : array[0..2501] of integer;

procedure dfs(x, y : integer);
var i : integer;
begin
  col[x, y] := k;
  for i := 1 to 4 do
    if (x + p[i].x >= 1) and (x + p[i].x <= n) and (y + p[i].y >= 1) and (y + p[i].y <= m) and (c[x, y] = c[x + p[i].x, y + p[i].y]) and (col[x + p[i].x, y + p[i].y] = 0) then
      dfs(x + p[i].x, y + p[i].y);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n, m);
  for i := 1 to n do begin
    for j := 1 to m do
      read(c[i, j]);
    readln;
  end;
  p[1].x := -1;
  p[1].y := 0;
  p[2].x := 0;
  p[2].y := 1;
  p[3].x := 1;
  p[3].y := 0;
  p[4].x := 0;
  p[4].y := -1;
  k := 0;
  for i := 1 to n do
    for j := 1 to m do
      if col[i, j] = 0 then begin
        inc(k);
        if c[i, j] = 'W' then
          prev[k] := 0
        else
          prev[k] := 1;
        dfs(i, j);
      end;
  for i := 1 to n do
    for j := 1 to m do
      for z := 1 to 4 do
        if (i + p[z].x >= 1) and (i + p[z].x <= n) and (j + p[z].y >= 1) and (j + p[z].y <= m) and (col[i, j] <> col[i + p[z].x, j + p[z].y]) then begin
          setlength(v[col[i, j]].u, v[col[i, j]].k + 2);
          inc(v[col[i, j]].k);
          v[col[i, j]].u[v[col[i, j]].k] := col[i + p[z].x, j + p[z].y];
        end;
  if k = 1 then begin
    if c[1, 1] = 'W' then
      write(0)
    else
      write(1);
    halt(0);
  end;
  ans := inf;
  for i := 1 to k do begin
    for j := 1 to k do
      d[j] := inf;
    d[i] := 0;
    l := 1;
    r := 1;
    queue[1] := i;
    while l <= r do begin
      cur := queue[l];
      inc(l);
      for j := 1 to v[cur].k do
        if d[v[cur].u[j]] > d[cur] + 1 then begin
          d[v[cur].u[j]] := d[cur] + 1;
          inc(r);
          queue[r] := v[cur].u[j];
        end;
    end;
    res := 0;
    for j := 1 to k do
      res := max(res, d[j]);
    if (prev[i] = 0) and (res mod 2 = 1) then
      inc(res);
    if (prev[i] = 1) and (res mod 2 = 0) then
      inc(res);
    ans := min(ans, res);
  end;
  write(ans);
end.