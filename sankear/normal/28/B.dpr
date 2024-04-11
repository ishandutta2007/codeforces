program solution;

{$APPTYPE CONSOLE}
{$O-,R+}

uses
  SysUtils,
  Math;

type
  tp = record
    a, b : integer;
  end;

var
  n, k, i, j : integer;
  used : array[0..101] of boolean;
  r, v1, v2 : array[0..101, 0..101] of boolean;
  p : array[0..101] of tp;

procedure dfs(x : integer);
var i : integer;
begin
  v1[k, x] := true;
  v2[k, p[x].a] := true;
  used[x] := true;
  for i := 1 to n do
    if (r[x, i]) and (not used[i]) then
      dfs(i);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].a);
  for i := 1 to n do
    read(p[i].b);
  for i := 1 to n do
    for j := 1 to n do
      if (abs(i - j) = p[i].b) or (abs(i - j) = p[j].b) then begin
        r[i, j] := true;
        r[j, i] := true;
      end;
  k := 0;
  for i := 1 to n do
    if not used[i] then begin
      inc(k);
      dfs(i);
    end;
  for i := 1 to k do
    for j := 1 to n do
      if v1[i, j] <> v2[i, j] then begin
        write('NO');
        halt(0);
      end;
  write('YES');
end.