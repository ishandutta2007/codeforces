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
  n, step, sz, i, j : integer;
  used : array[0..100001] of boolean;
  a : array[0..100001] of integer;

procedure dfs(x : integer);
begin
  inc(sz);
  used[x] := true;
  x := x + step;
  if x > n then
    x := x - n;
  if (a[x] = 1) and (not used[x]) then
    dfs(x);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 3 to n do
    if n mod i = 0 then begin
      step := n div i;
      for j := 1 to n do
        used[j] := false;
      for j := 1 to n do
        if (a[j] = 1) and (not used[j]) then begin
          sz := 0;
          dfs(j);
          if sz = i then begin
            writeln('YES');
            halt(0);
          end;
        end;
    end;
  writeln('NO');
end.