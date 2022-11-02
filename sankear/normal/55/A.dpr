program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O-,R+,Q+}
{O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, i : integer;
  used : array[0..1001] of boolean;

function get(x, y : integer) : integer;
begin
  result := x + y;
  while result > n do
    result := result - n;
end;

procedure dfs(x, y : integer);
var nx : integer;
begin
  used[x] := true;
  nx := get(x, y);
  if not used[nx] then
    dfs(nx, y + 1);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  dfs(1, 1);
  for i := 1 to n do
    if not used[i] then begin
      writeln('NO');
      halt(0);
    end;
  writeln('YES');
end.