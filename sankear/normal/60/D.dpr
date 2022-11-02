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
  maxv = round(2e7);

var
  n, a, b, c, z, ans : integer;
  i, j : int64;
  used : array[0..20000001] of boolean;
  p, rank : array[0..20000001] of integer;

function gcd(a, b : integer) : integer;
begin
  if b = 0 then begin
    result := a;
    exit;
  end;
  result := gcd(b, a mod b);
end;

function get(v : integer) : integer;
begin
  if p[v] <> v then
    p[v] := get(p[v]);
  result := p[v];
end;

procedure merge(v1, v2 : integer);
begin
  if rank[v1] = rank[v2] then begin
    p[v2] := v1;
    inc(rank[v1]);
    exit;
  end;
  if rank[v1] < rank[v2] then begin
    p[v1] := v2;
    exit;
  end;
  p[v2] := v1;
end;

procedure add(a, b : integer);
begin
  if (used[a]) and (used[b]) then
    merge(get(a), get(b));
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for z := 1 to n do begin
    read(a);
    used[a] := true;
    p[a] := a;
    rank[a] := 1;
  end;
  i := 1;
  while i * i <= maxv do begin
    j := 1;
    while (j <= i) and (i * i + j * j <= maxv) do begin
      if ((i + j) mod 2 = 1) and (gcd(i, j) = 1) then begin
        a := i * i - j * j;
        b := 2 * i * j;
        c := i * i + j * j;
        add(a, b);
        add(a, c);
        add(b, c);
      end;
      j := j + 1;
    end;
    i := i + 1;
  end;
  ans := 0;
  for z := 1 to maxv do
    if (used[z]) and (get(z) = z) then
      inc(ans);
  writeln(ans);
end.