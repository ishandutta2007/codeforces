program solution;

{$APPTYPE CONSOLE}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    x, y : int64;
  end;
  tc = record
    x, y, r : int64;
  end;
  tv = record
    num : array[0..1001] of integer;
    k : integer;
  end;

var
  n, m, k, i, j, ans, a, b : integer;
  fl : boolean;
  r : array[0..1001, 0..1001] of boolean;
  used : array[0..1001] of boolean;
  p : array[0..1001] of tp;
  c : array[0..1001] of tc;
  v : array[0..1001] of tv;

function check(var a : tp; var b : tc) : boolean;
begin
  result := (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= b.r * b.r;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, m, k);
  for i := 1 to n do
    read(p[i].x, p[i].y);
  for i := 1 to m do
    read(c[i].r, c[i].x, c[i].y);
  for i := 1 to n do
    for j := 1 to m do
      if check(p[i], c[j]) then begin
        r[i, j] := true;
        inc(v[i].k);
        v[i].num[v[i].k] := j;
      end;
  for i := 1 to k do begin
    read(a, b);
    fillchar(used, sizeof(used), 0);
    ans := 0;
    for j := 1 to v[a].k do
      if r[a, v[a].num[j]] <> r[b, v[a].num[j]] then begin
        if not used[v[a].num[j]] then
          inc(ans);
        used[v[a].num[j]] := true;
      end;
    for j := 1 to v[b].k do
      if r[a, v[b].num[j]] <> r[b, v[b].num[j]] then begin
        if not used[v[b].num[j]] then
          inc(ans);
        used[v[b].num[j]] := true;
      end;
    writeln(ans);
  end;
end.