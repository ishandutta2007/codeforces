program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, k, t, ans, num, i, j : integer;
  a, d, p : array[0..2001] of integer;
  can : array[0..2001, 0..2001] of boolean;

function gcd(a, b : integer) : integer;
begin
  if b = 0 then
    result := a
  else
    result := gcd(b, a mod b);
end;

procedure wrans(n : integer);
begin
  write(a[n], ' ');
  if p[n] > 0 then
    wrans(p[n]);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  k := 0;
  i := 1;
  while i * i <= n do begin
    if n mod i = 0 then begin
      inc(k);
      a[k] := i;
      if i * i < n then begin
        inc(k);
        a[k] := n div i;
      end;
    end;
    inc(i);
  end;
  for i := 1 to k - 1 do
    for j := k downto i + 1 do
      if a[i] > a[j] then begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;
      end;
  for i := 2 to k do
    for j := 1 to i - 1 do
      if gcd(a[j], a[i]) = a[j] then
        can[j, i] := true;
  for i := 1 to k do begin
    d[i] := 1;
    p[i] := 0;
    for j := 1 to i - 1 do
      if (can[j, i]) and (d[j] + 1 > d[i]) then begin
        d[i] := d[j] + 1;
        p[i] := j;
      end;
  end;
  ans := 0;
  num := 0;
  for i := 1 to k do
    if d[i] > ans then begin
      ans := d[i];
      num := i;
    end;
  wrans(num);
  writeln;
end.