program solution;

{$APPTYPE CONSOLE}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;
  
type
  tp = record
    a, c : integer;
  end;
  td = record
    a, num, maxa, k, h, l, r : integer;
  end;

var
  n, i, j, curv, l, r, x, res, res1, res2, res3 : integer;
  p : array[0..100001] of tp;
  d : array[0..100001] of td;

procedure calc(v : integer);
begin
  if v = 0 then
    exit;
  d[v].maxa := max(d[v].a, max(d[d[v].l].maxa, d[d[v].r].maxa));
  d[v].k := d[d[v].l].k + d[d[v].r].k + 1;
end;

procedure split(v, k : integer; var l, r : integer);
begin
  if v = 0 then begin
    l := 0;
    r := 0;
    exit;
  end;
  if d[d[v].l].k + 1 <= k then begin
    l := v;
    split(d[v].r, k - d[d[v].l].k - 1, d[v].r, r);
  end
  else begin
    r := v;
    split(d[v].l, k, l, d[v].l);
  end;
  calc(v);
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
  if d[v1].h > d[v2].h then begin
    result := v1;
    d[v1].r := merge(d[v1].r, v2);
  end
  else begin
    result := v2;
    d[v2].l := merge(v1, d[v2].l);
  end;
  calc(result);
end;

procedure dfs(v : integer);
begin
  if v = 0 then
    exit;
  dfs(d[v].l);
  write(d[v].num, ' ');
  dfs(d[v].r);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].a, p[i].c);
  randomize;
  curv := 0;
  d[0].maxa := 0;
  d[0].k := 0;
  for i := 1 to n do begin
    l := max(1, i - p[i].c);
    r := i - 1;
    res := i;
    while l <= r do begin
      x := l + (r - l) div 2;
      split(curv, i - 1, res1, res3);
      split(res1, x - 1, res1, res2);
      if d[res2].maxa < p[i].a then begin
        res := x;
        r := x - 1;
      end
      else
        l := x + 1;
      curv := merge(res1, merge(res2, res3));
    end;
    d[i].a := p[i].a;
    d[i].num := i;
    d[i].maxa := p[i].a;
    d[i].k := 1;
    d[i].h := random(2000000000);
    d[i].l := 0;
    d[i].r := 0;  
    split(curv, res - 1, res1, res2);
    curv := merge(res1, merge(i, res2));
  end;
  dfs(curv);
end.