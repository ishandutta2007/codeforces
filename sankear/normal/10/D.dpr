program codeforces;

{$APPTYPE CONSOLE}
{$O-}

uses
  SysUtils,
  Math;

const
  maxn = 500;
  maxm = 500;

var
  n, m, i, j, k, curmax, curnum, ans, l, r : integer;
  a : array[1..maxn] of integer;
  b : array[1..maxm] of integer;
  d, p1, p2, maxv, maxnum : array[0..maxn, 0..maxm] of integer;

procedure wrans(x, y : integer);
begin
  if (p1[x, y] > 0) and (p2[x, y] > 0) then
    wrans(p1[x, y], p2[x, y]);
  write(a[x], ' ');
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(a[i]);
  read(m);
  for i := 1 to m do
    read(b[i]);
  for i := 1 to n do begin
    for j := 1 to m do
      if a[i] = b[j] then begin
        d[i, j] := 1;
        for k := 1 to i - 1 do
          if (a[k] < a[i]) and (maxv[k, j - 1] + 1 > d[i, j]) then begin
            d[i, j] := maxv[k, j - 1] + 1;
            p1[i, j] := k;
            p2[i, j] := maxnum[k, j - 1];
          end;
      end
      else
        d[i, j] := 0;
    curmax := 0;
    curnum := 0;
    for j := 1 to m do begin
      if d[i, j] > curmax then begin
        curmax := d[i, j];
        curnum := j;
      end;
      maxv[i, j] := curmax;
      maxnum[i, j] := curnum;
    end;
  end;
  ans := 0;
  for i := 1 to n do
    for j := 1 to m do
      if d[i, j] > ans then begin
        ans := d[i, j];
        l := i;
        r := j;
      end;
  writeln(ans);
  if ans > 0 then
    wrans(l, r);
end.