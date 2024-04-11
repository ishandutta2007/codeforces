program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    b : integer;
    name : string;
  end;
  tap = array[0..100001] of tp;

var
  n, m, k, mm, res, l, r, mid, ans1, ans2, p, i : integer;
  name : string;
  used : array[0..100001] of boolean;
  a : array[0..100001] of integer;
  p1, p2 : tap;

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

function less(var a, b : tp) : boolean;
begin
  if a.b = b.b then begin
    result := a.name < b.name;
    exit;
  end;
  result := a.b > b.b;
end;

procedure sort1(l, r : integer);
var ea, t, i, j : integer;
begin
  if l >= r then
    exit;
  ea := a[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while a[i] > ea do
      inc(i);
    while ea > a[j] do
      dec(j);
    if i <= j then begin
      t := a[i];
      a[i] := a[j];
      a[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort1(i, r);
  sort1(l, j);
end;

procedure sort2(var p : tap; l, r : integer);
var ep, t : tp;
i, j : integer;
begin
  if l >= r then
    exit;
  ep := p[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while less(p[i], ep) do
      inc(i);
    while less(ep, p[j]) do
      dec(j);
    if i <= j then begin
      t := p[i];
      p[i] := p[j];
      p[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort2(p, i, r);
  sort2(p, l, j);
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    gets(p1[i].name);
    read(p1[i].b);
  end;
  read(m);
  for i := 1 to m do
    read(a[i]);
  gets(name);
  mm := m;
  sort1(1, m);
  sort2(p1, 1, n);
  if m = 0 then begin
    for i := 1 to n do
      if p1[i].name = name then begin
        writeln(i, ' ', i);
        break;
      end;
    halt(0);
  end;
  for i := 1 to n do
    p2[i] := p1[i];
  for i := 1 to n do
    if p2[i].name = name then begin
      p := i;
      break;
    end;
  if m = n then begin
    p2[p].b := p2[p].b + a[m];
    dec(m);
  end;
  k := 1;
  if k <= m then begin
    for i := n downto p + 1 do
      if p2[i].name <> name then begin
        p2[i].b := p2[i].b + a[k];
        if not less(p2[i], p2[p]) then begin
          p2[i].b := p2[i].b - a[k];
          continue;
        end;
        used[i] := true;
        inc(k);
        if k > m then
          break;
      end;
    if k <= m then begin
      for i := n downto 1 do
        if (p2[i].name <> name) and (not used[i]) then begin
          p2[i].b := p2[i].b + a[k];
          inc(k);
          if k > m then
            break;
        end;
    end;
  end;
  sort2(p2, 1, n);
  for i := 1 to n do
    if p2[i].name = name then begin
      ans2 := i;
      break;
    end;
  for i := 1 to n do
    p2[i] := p1[i];
  for i := 1 to n do
    if p2[i].name = name then begin
      p2[i].b := p2[i].b + a[1];
      break;
    end;
  sort2(p2, 1, n);
  for i := 1 to n do
    p1[i] := p2[i];
  for i := 1 to n do
    if p1[i].name = name then begin
      p := i;
      break;
    end;
  m := mm;
  if m = 1 then
    ans1 := p
  else begin
    l := p;
    r := min(p + m - 1, ans2);
    while l <= r do begin
      mid := l + (r - l) div 2;
      for i := 1 to n do
        p2[i] := p1[i];
      k := 2;
      for i := p + 1 to mid do begin
        p2[i].b := p2[i].b + a[k];
        inc(k);
      end;
      if k <= m then begin
        for i := 1 to p - 1 do begin
          p2[i].b := p2[i].b + a[k];
          inc(k);
          if k > m then
            break;
        end;
      end;
      if k <= m then begin
        for i := n downto p + 1 do begin
          p2[i].b := p2[i].b + a[k];
          inc(k);
          if k > m then
            break;
        end;
      end;
      sort2(p2, 1, n);
      for i := 1 to n do
        if p2[i].name = name then begin
          res := i;
          break;
        end;
      if res <= mid then begin
        ans1 := mid;
        r := mid - 1;
      end
      else
        l := mid + 1;
    end;
  end;
  writeln(ans1, ' ', ans2);
end.