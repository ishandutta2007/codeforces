program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, k, a, b, c, d, i : integer;
  fl : boolean;
  l : array[0..101, 0..101] of integer;
  used : array[0..101] of boolean;
  ans : array[0..101] of int64;
  f, kol, first : array[0..101] of integer;
  go, next : array[0..10001] of integer;
  nod, val : array[0..10001] of int64;

function gcd(a, b : int64) : int64;
begin
  if b = 0 then
    result := a
  else
    result := gcd(b, a mod b);
end;

procedure add(a, b : integer; c, d : int64);
begin
  inc(k);
  go[k] := b;
  val[k] := c;
  nod[k] := d;
  next[k] := first[a];
  first[a] := k;
end;

procedure dfs1(v : integer);
var i : integer;
begin
  inc(kol[k]);
  l[k, kol[k]] := v;
  used[v] := true;
  i := first[v];
  while i > 0 do begin
    if not used[go[i]] then
      dfs1(go[i]);
    i := next[i];
  end;
end;

procedure dfs2(v : integer);
var i, j : integer;
begin
  if not fl then
    exit;
  i := first[v];
  while i > 0 do begin
    j := go[i];
    if ans[j] = 0 then begin
      if val[i] mod ans[v] <> 0 then begin
        fl := false;
        exit;
      end;
      ans[j] := val[i] div ans[v];
      if ans[j] > 1000000 then begin
        fl := false;
        exit;
      end;
      if gcd(ans[v], ans[j]) <> nod[i] then begin
        fl := false;
        exit;
      end;
      dfs2(j);
    end
    else
      if (ans[j] <> val[i] div ans[v]) or (gcd(ans[v], ans[j]) <> nod[i]) then begin
        fl := false;
        exit;
      end;
    i := next[i];
  end;
end;

procedure solve(v : integer);
var ff, i : integer;
ch, j : int64;
begin
  ff := f[v];
  i := first[ff];
  if i = 0 then begin
    ans[ff] := 1;
    exit;
  end;
  ch := val[i];
  j := 1;
  while j * j <= ch do begin
    if ch mod j = 0 then begin
      for i := 1 to kol[v] do
        ans[l[v, i]] := 0;
      ans[ff] := j;
      fl := true;
      dfs2(ff);
      if fl then
        exit;
      if j * j < ch then begin
        for i := 1 to kol[v] do
          ans[l[v, i]] := 0;
        ans[ff] := ch div j;
        if ans[ff] <= 1000000 then begin
        fl := true;
        dfs2(ff);
        if fl then
          exit;
        end;
      end;
    end;
    j := j + 1;
  end;
  writeln('NO');
  halt(0);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  k := 0;
  for i := 1 to m do begin
    read(a, b, c, d);
    add(a, b, int64(c) * d, int64(c));
    add(b, a, int64(c) * d, int64(c));
  end;
  k := 0;
  for i := 1 to n do
    if not used[i] then begin
      inc(k);
      f[k] := i;
      dfs1(i);
    end;
  for i := 1 to k do
    solve(i);
  writeln('YES');
  for i := 1 to n do
    write(ans[i], ' ');
  writeln;
end.