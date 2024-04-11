program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, i, j, k : integer;
  l, r, ans : array[1..1000] of integer;
  used : array[1..1000] of boolean;

procedure sort(lft, rgh : integer);
var x, t, i, j : integer;
begin
  x := r[lft + random(rgh - lft + 1)];
  i := lft;
  j := rgh;
  while i <= j do begin
    while r[i] < x do
      inc(i);
    while r[j] > x do
      dec(j);
    if i <= j then begin
      t := l[i];
      l[i] := l[j];
      l[j] := t;
      t := r[i];
      r[i] := r[j];
      r[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < rgh then
    sort(i, rgh);
  if j > lft then
    sort(lft, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do begin
    read(l[i], r[i]);
    if l[i] > r[i] then begin
      j := l[i];
      l[i] := r[i];
      r[i] := j;
    end;
  end;
  sort(1, n);
  k := 0;
  for i := 1 to n do
    if not used[i] then begin
      inc(k);
      ans[k] := r[i];
      for j := 1 to n do
        if (l[j] <= r[i]) and (r[j] >= r[i]) then
          used[j] := true;
    end;
  writeln(k);
  for i := 1 to k do
    write(ans[i], ' ');
end.