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
  n, k, res, next, i, j, z, ii, jj : integer;
  a, aa, bb : array[0..1001] of integer;
  calc, f, t, pi, pj : array[0..1001, 0..1001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    for j := i to n do
      if (j - i + 1) mod 2 = 0 then
        calc[i, j] := calc[i, j - 2] + max(a[j - 1], a[j])
      else
        calc[i, j] := inf;
  f[n, n + 1] := a[n];
  t[n, n + 1] := 1;
  f[n - 1, n + 1] := a[n - 1];
  t[n - 1, n + 1] := 1;
  for i := n - 1 downto 1 do
    for j := min(n, i + 2) downto i + 1 do begin
      f[i, j] := inf;
      res := a[i] + calc[j, n];
      if res < f[i, j] then begin
        f[i, j] := res;
        t[i, j] := 1;
      end;
      for z := j to n do begin
        res := max(a[i], a[z]) + f[z + 1, z + 2] + calc[j, z - 1];
        if res < f[i, j] then begin
          f[i, j] := res;
          t[i, j] := 2;
          pi[i, j] := z + 1;
          pj[i, j] := z + 2;
        end;
        if z = j then
          continue;
        res := max(a[i], a[z]) + f[z - 1, z + 1] + calc[j, z - 2];
        if res < f[i, j] then begin
          f[i, j] := res;
          t[i, j] := 3;
          pi[i, j] := z - 1;
          pj[i, j] := z + 1;
        end;
      end;
    end;
  k := 0;
  i := 1;
  j := 2;
  while (i >= 1) and (i <= n) do begin
    if t[i, j] = 1 then begin
      z := j;
      while z <= n do begin
        inc(k);
        aa[k] := z;
        bb[k] := z + 1;
        z := z + 2;
      end;
      inc(k);
      aa[k] := i;
      break;
    end;
    if t[i, j] = 2 then begin
      next := pi[i, j] - 1;
      if (next - j) mod 2 = 0 then begin
        z := j;
        while z < next do begin
          inc(k);
          aa[k] := z;
          bb[k] := z + 1;
          z := z + 2;
        end;
      end;
    end
    else begin
      next := pi[i, j] + 1;
      if (next - j - 1) mod 2 = 0 then begin
        z := j;
        while z < next - 1 do begin
          inc(k);
          aa[k] := z;
          bb[k] := z + 1;
          z := z + 2;
        end;
      end;
    end;
    inc(k);
    aa[k] := i;
    bb[k] := next;
    ii := pi[i, j];
    jj := pj[i, j];
    i := ii;
    j := jj;
  end;
  writeln(f[1, 2]);
  for i := 1 to k do
    if bb[i] > 0 then
      writeln(aa[i], ' ', bb[i]);
  for i := 1 to k do
    if bb[i] = 0 then
      writeln(aa[i]);
end.