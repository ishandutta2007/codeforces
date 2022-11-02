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

var
  n, m, k, sz, a, b, ans, i, j : integer;
  used : array[0..100001] of boolean;
  first, c, d, e, f : array[0..100001] of integer;
  go, next : array[0..200001] of integer;

procedure add(a, b : integer);
begin
  inc(k);
  go[k] := b;
  next[k] := first[a];
  first[a] := k;
end;

procedure dfs(a : integer);
var i : integer;
begin
  used[a] := true;
  inc(sz);
  i := first[a];
  while i > 0 do begin
    if not used[go[i]] then
      dfs(go[i]);
    i := next[i];
  end;
end;

function good(a : integer) : boolean;
var b : integer;
begin
  result := true;
  while a > 0 do begin
    b := a mod 10;
    if (b <> 4) and (b <> 7) then begin
      result := false;
      exit;
    end;
    a := a div 10;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  k := 0;
  for i := 1 to m do begin
    read(a, b);
    add(a, b);
    add(b, a);
  end;
  for i := 1 to n do
    if not used[i] then begin
      sz := 0;
      dfs(i);
      inc(c[sz]);
    end;
  k := 0;
  for i := 1 to n do
    if c[i] > 0 then begin
      j := 1;
      while j <= c[i] do begin
        inc(k);
        d[k] := i * j;
        e[k] := j;
        c[i] := c[i] - j;
        j := j * 2;
      end;
      if c[i] > 0 then begin
        inc(k);
        d[k] := i * c[i];
        e[k] := c[i];
      end;
    end;
  for i := 1 to n do
    f[i] := inf;
  for i := 1 to k do
    for j := n downto d[i] do
      f[j] := min(f[j], f[j - d[i]] + e[i]);
  ans := inf;
  for i := 1 to n do
    if good(i) then
      ans := min(ans, f[i]);
  if ans = inf then begin
    writeln(-1);
    halt;
  end;
  writeln(ans - 1);
end.