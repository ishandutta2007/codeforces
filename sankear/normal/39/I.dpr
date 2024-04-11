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
  n, m, k, a, b, cur, l, r, ans, i : integer;
  queue, d, go, next, first : array[0..100001] of integer;

procedure add(a, b : integer);
begin
  inc(k);
  go[k] := b;
  next[k] := first[a];
  first[a] := k;
end;

function gcd(a, b : integer) : integer;
begin
  if b = 0 then
    result := a
  else
    result := gcd(b, a mod b);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  k := 0;
  for i := 1 to m do begin
    read(a, b);
    add(a, b);
  end;
  for i := 1 to n do
    d[i] := inf;
  d[1] := 0;
  l := 1;
  r := 1;
  queue[1] := 1;
  ans := 0;
  while l <= r do begin
    cur := queue[l];
    inc(l);
    i := first[cur];
    while i > 0 do begin
      if d[go[i]] > d[cur] + 1 then begin
        d[go[i]] := d[cur] + 1;
        inc(r);
        queue[r] := go[i];
      end
      else
        ans := gcd(ans, d[cur] + 1 - d[go[i]]);
      i := next[i];
    end;
  end;
  writeln(ans);
  k := 0;
  for i := 1 to n do
    if (d[i] < inf) and (d[i] mod ans = 0) then
      inc(k);
  writeln(k);
  for i := 1 to n do
    if (d[i] < inf) and (d[i] mod ans = 0) then
      write(i, ' ');
  writeln;
end.