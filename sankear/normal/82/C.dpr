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
  int = 0..5001;

var
  n, k, a, b, c, i, j : integer;
  used : array[0..5001] of boolean;
  first, r, num, pv, pc, pos, ans : array[0..5001] of integer;
  go, cnt, next : array[0..10001] of integer;
  bad : array[0..5001, 0..20001] of int;

procedure swap(var a, b : integer);
var c : integer;
begin
  c := a;
  a := b;
  b := c;
end;

procedure add(a, b, c : integer);
begin
  inc(k);
  go[k] := b;
  cnt[k] := c;
  next[k] := first[a];
  first[a] := k;
end;

procedure dfs(a : integer);
var i : integer;
begin
  used[a] := true;
  i := first[a];
  while i > 0 do begin
    if not used[go[i]] then begin
      pv[go[i]] := a;
      pc[go[i]] := cnt[i];
      dfs(go[i]);
    end;
    i := next[i];
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  //writeln((sizeof(used) + sizeof(first) + sizeof(r) + sizeof(num) + sizeof(pv) + sizeof(pc) + sizeof(pos) + sizeof(ans) + sizeof(go) + sizeof(cnt) + sizeof(next) + sizeof(bad)) div 1024 div 1024);
  read(n);
  for i := 1 to n do begin
    read(r[i]);
    pos[i] := i;
    num[i] := i;
  end;
  k := 0;
  for i := 1 to n - 1 do begin
    read(a, b, c);
    add(a, b, c);
    add(b, a, c);
  end;
  dfs(1);
  for i := 2 to n - 1 do
    for j := n downto i + 1 do
      if r[i] > r[j] then begin
        swap(r[i], r[j]);
        swap(num[i], num[j]);
      end;
  for i := 2 to n do
    bad[i, 0] := 1;
  for i := 2 to n do begin
    ans[num[i]] := 0;
    while pos[num[i]] > 1 do begin
      while bad[pos[num[i]], ans[num[i]]] > pc[pos[num[i]]] do begin
        inc(ans[num[i]]);
        inc(bad[pos[num[i]], ans[num[i]]]);
      end;
      inc(ans[num[i]]);
      pos[num[i]] := pv[pos[num[i]]];
      inc(bad[pos[num[i]], ans[num[i]]]);
    end;
  end;
  for i := 1 to n - 1 do
    write(ans[i], ' ');
  writeln(ans[n]);
end.