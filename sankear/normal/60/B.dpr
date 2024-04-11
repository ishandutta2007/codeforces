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
  k, n, m, i, j, z, a, b, ans : integer;
  aa : array[0..11, 0..11, 0..11] of char;
  used : array[0..11, 0..11, 0..11] of boolean;

procedure getc(var c : char);
begin
  read(c);
  while not (c in ['.', '#']) do
    read(c);
end;

procedure dfs(a, b, c : integer);
var i, j, z : integer;
begin
  used[a, b, c] := true;
  for i := -1 to 1 do
    for j := -1 to 1 do
      for z := -1 to 1 do
        if (abs(i) + abs(j) + abs(z) = 1) and (a + i >= 1) and (a + i <= k) and (b + j >= 1) and (b + j <= n) and (c + z >= 1) and (c + z <= m) and (aa[a + i, b + j, c + z] = '.') and (not used[a + i, b + j, c + z]) then
          dfs(a + i, b + j, c + z);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(k, n, m);
  for i := 1 to k do
    for j := 1 to n do
      for z := 1 to m do
        getc(aa[i, j, z]);
  read(a, b);
  dfs(1, a, b);
  ans := 0;
  for i := 1 to k do
    for j := 1 to n do
      for z := 1 to m do
        if used[i, j, z] then
          inc(ans);
  writeln(ans);
end.