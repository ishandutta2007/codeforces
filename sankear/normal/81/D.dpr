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
    a, b : integer;
  end;

var
  n, m, cur, i, j : integer;
  t : tp;
  p : array[0..41] of tp;
  ans : array[0..1001] of integer;

function prev(a : integer) : integer;
begin
  if a = 1 then
    result := n
  else
    result := a - 1;
end;

function next(a : integer) : integer;
begin
  if a = n then
    result := 1
  else
    result := a + 1;
end;

function more(var a, b : tp) : boolean;
begin
  result := a.a < b.a;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to m do begin
    read(p[i].a);
    p[i].a := min(p[i].a, n div 2);
    p[i].b := i;
  end;
  for i := 1 to m - 1 do
    for j := m downto i + 1 do
      if more(p[i], p[j]) then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  cur := 1;
  i := 1;
  while i <= n do begin
    while (cur <= m) and (p[cur].a = 0) do
      inc(cur);
    if cur > m then begin
      writeln(-1);
      halt;
    end;
    ans[i] := p[cur].b;
    dec(p[cur].a);
    i := i + 2;
  end;
  i := 2;
  while i <= n do begin
    while (cur <= m) and (p[cur].a = 0) do
      inc(cur);
    if cur > m then begin
      writeln(-1);
      halt;
    end;
    ans[i] := p[cur].b;
    dec(p[cur].a);
    i := i + 2;
  end;
  for i := 1 to n do
    if ans[i] = 0 then begin
      writeln(-1);
      halt;
    end;
  for i := 1 to n do
    write(ans[i], ' ');
  writeln;
end.