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
  n, m, k, a, b, i, j, z, h : integer;
  can, c, cc : array[0..101, 0..101] of boolean;
  l, ll : array[0..2001] of integer;

procedure dfs(a, b, c : integer);
var i : integer;
begin
  if b = 0 then begin
    if a <> l[1] then
      exit;
    for i := 1 to c do
      write(l[i], ' ');
    for i := 1 to k do
      write(ll[i], ' ');
    writeln;
    halt(0);
  end;
  for i := 1 to n do
    if cc[a, i] then begin
      cc[a, i] := false;
      cc[i, a] := false;
      inc(k);
      ll[k] := i;
      dfs(i, b - 1, c);
      dec(k);
      cc[a, i] := true;
      cc[i, a] := true;
    end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to m + 1 do begin
    read(l[i]);
    if i > 1 then begin
      a := l[i - 1];
      b := l[i];
      can[a, b] := true;
      can[b, a] := true;
    end;
  end;
  for i := m downto 1 do begin
    for j := 1 to n do
      for z := 1 to n do
        c[j, z] := can[j, z];
    for j := 2 to i do begin
      a := l[j - 1];
      b := l[j];
      c[a, b] := false;
      c[b, a] := false;
    end;
    a := l[i];
    for j := l[i + 1] + 1 to n do
      if c[a, j] then begin
        for z := 1 to n do
          for h := 1 to n do
            cc[z, h] := c[z, h];
        cc[a, j] := false;
        cc[j, a] := false;
        k := 1;
        ll[1] := j;
        dfs(j, m - i, i);
      end;
  end;
  writeln('No solution');
end.