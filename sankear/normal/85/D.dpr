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
  rand = round(2e9);

type
  td = record
    h, k, l, r : integer;
    a, sum : int64;
  end;

var
  n, a, k, sw, sum, i, j : integer;
  s : string;
  d : array[0..100001] of td;
  cv : array[0..5] of integer;
  cur, scur : array[0..5, 0..3] of integer;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z']) do
    read(c);
  while c in ['a'..'z'] do begin
    s := s + c;
    read(c);
  end;
end;

procedure calc(v : integer);
begin
  d[v].sum := d[d[v].l].sum + d[d[v].r].sum + d[v].a;
  d[v].k := d[d[v].l].k + d[d[v].r].k + 1;
end;

procedure split(v, a : integer; var l, r : integer);
begin
  if v = 0 then begin
    l := 0;
    r := 0;
    exit;
  end;
  if d[v].a < a then begin
    split(d[v].r, a, d[v].r, r);
    l := v;
  end
  else begin
    split(d[v].l, a, l, d[v].l);
    r := v;
  end;
  calc(v);
end;

function merge(l, r : integer) : integer;
begin
  if l = 0 then begin
    result := r;
    exit;
  end;
  if r = 0 then begin
    result := l;
    exit;
  end;
  if d[l].h > d[r].h then begin
    d[l].r := merge(d[l].r, r);
    result := l;
  end
  else begin
    d[r].l := merge(l, d[r].l);
    result := r;
  end;
  calc(result);
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  k := 0;
  for i := 1 to n do begin
    gets(s);
    if s = 'sum' then begin
      writeln(d[cv[3]].sum);
      continue;
    end;
    read(a);
    if s = 'add' then begin
      sum := 0;
      for j := 0 to 4 do begin
        split(cv[j], a, cur[j, 1], cur[j, 2]);
        sum := sum + d[cur[j, 1]].k;
      end;
      for j := 0 to 4 do
        scur[(j + 1) mod 5, 2] := cur[j, 2];
      for j := 0 to 4 do
        cur[j, 2] := scur[j, 2];
      sum := (sum + 1) mod 5;
      inc(k);
      d[k].a := a;
      d[k].sum := a;
      d[k].k := 1;
      d[k].h := random(rand);
      d[k].l := 0;
      d[k].r := 0;
      cv[sum] := merge(cur[sum, 1], merge(k, cur[sum, 2]));
      for j := 0 to 4 do
        if j <> sum then
          cv[j] := merge(cur[j, 1], cur[j, 2]);
      continue;
    end;
    for j := 0 to 4 do begin
      split(cv[j], a, cur[j, 1], cur[j, 2]);
      split(cur[j, 2], a + 1, sw, cur[j, 2]);
    end;
    for j := 0 to 3 do
      scur[j, 2] := cur[j + 1, 2];
    scur[4, 2] := cur[0, 2];
    for j := 0 to 4 do
      cur[j, 2] := scur[j, 2];
    for j := 0 to 4 do
      cv[j] := merge(cur[j, 1], cur[j, 2]);
  end;
end.