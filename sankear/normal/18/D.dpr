program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type
  tl = array[0..1000] of integer;

var
  n, i, j, k, x : integer;
  ans, res : tl;
  s : string;
  pow : array[0..2000] of tl;
  maxd, d : array[0..5000] of tl;
  used : array[1..5000, 0..2000] of boolean;

procedure sum(var a, b : tl);
var i, ost : integer;
begin
  if a[0] < b[0] then begin
    for i := a[0] + 1 to b[0] do
      a[i] := 0;
    a[0] := b[0];
  end;
  if a[0] > b[0] then begin
    for i := b[0] + 1 to a[0] do
      b[i] := 0;
  end;
  ost := 0;
  for i := 1 to a[0] do begin
    a[i] := a[i] + b[i] + ost;
    ost := a[i] div 10000;
    a[i] := a[i] mod 10000;
  end;
  if ost > 0 then begin
    inc(a[0]);
    a[a[0]] := ost;
  end;
end;

function cmp(var a, b : tl) : boolean;
var i : integer;
begin
  if a[0] = b[0] then begin
    i := a[0];
    while (i > 0) and (a[i] = b[i]) do
      dec(i);
    result := (i > 0) and (a[i] > b[i]);
  end
  else
    result := a[0] > b[0];
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  pow[0, 0] := 1;
  pow[0, 1] := 1;
  for i := 1 to 2000 do begin
    pow[i, 0] := 1;
    pow[i, 1] := 0;
    sum(pow[i], pow[i - 1]);
    sum(pow[i], pow[i - 1]);
  end;
  readln(n);
  for i := 0 to n do begin
    d[i, 0] := 1;
    d[i, 1] := 0;
  end;
  for i := 1 to n do begin
    readln(s);
    k := 0;
    x := 0;
    for j := 1 to length(s) do
      if s[j] = ' ' then
        inc(k)
      else
        if k = 1 then
          x := x * 10 + ord(s[j]) - ord('0');
    if s[1] = 'w' then begin
      for j := 1 to i do
        used[j, x] := true;
    end;
    d[i] := d[i - 1];
    if s[1] = 's' then begin
      for j := i - 1 downto 0 do
        if used[j + 1, x] then begin
          res := d[j];
          sum(res, pow[x]);
          if cmp(res, d[i]) then
            d[i] := res;
          break;
        end;
    end;
  end;
  write(d[n, d[n, 0]]);
  for i := d[n, 0] - 1 downto 1 do begin
    if d[n, i] < 1000 then
      write(0);
    if d[n, i] < 100 then
      write(0);
    if d[n, i] < 10 then
      write(0);
    write(d[n, i]);
  end;
end.