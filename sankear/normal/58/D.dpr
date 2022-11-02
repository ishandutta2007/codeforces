program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, i : integer;
  sum, slen : int64;
  d : char;
  w : array[0..10001] of string;
  used : array[0..10001] of boolean;
  len, num1, num2 : array[0..10001] of integer;

function sless1(a, b : integer) : boolean;
var minlen, i : integer;
begin
  minlen := min(len[a], len[b]);
  i := 1;
  while (i <= minlen) and (w[a, i] = w[b, i]) do
    inc(i);
  result := (i <= minlen) and (w[a, i] < w[b, i]);
end;

procedure sort1(l, r : integer);
var enum, t, i, j : integer;
begin
  if l >= r then
    exit;
  enum := num1[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while sless1(num1[i], enum) do
      inc(i);
    while sless1(enum, num1[j]) do
      dec(j);
    if i <= j then begin
      t := num1[i];
      num1[i] := num1[j];
      num1[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort1(i, r);
  sort1(l, j);
end;

function sless2(a, b : integer) : boolean;
begin
  if len[a] <> len[b] then begin
    result := len[a] < len[b];
    exit;
  end;
  result := sless1(a, b);
end;

procedure sort2(l, r : integer);
var enum, t, i, j : integer;
begin
  if l >= r then
    exit;
  enum := num2[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while sless2(num2[i], enum) do
      inc(i);
    while sless2(enum, num2[j]) do
      dec(j);
    if i <= j then begin
      t := num2[i];
      num2[i] := num2[j];
      num2[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort2(i, r);
  sort2(l, j);
end;

function eq(a, b : integer) : boolean;
var i : integer;
begin
  if len[a] <> len[b] then begin
    result := false;
    exit;
  end;
  i := 1;
  while (i <= len[a]) and (w[a, i] = w[b, i]) do
    inc(i);
  result := i > len[a];
end;

procedure find1(num : integer);
var l, r, mid : integer;
begin
  l := 1;
  r := n;
  while l <= r do begin
    mid := l + (r - l) div 2;
    if eq(num2[mid], num) then begin
      write(w[num2[mid]], d);
      used[num2[mid]] := true;
      exit;
    end;
    if sless2(num2[mid], num) then
      l := mid + 1
    else
      r := mid - 1;
  end;
end;

procedure find2(flen : integer);
var res, l, r, mid : integer;
begin
  res := 0;
  l := 1;
  r := n;
  while l <= r do begin
    mid := l + (r - l) div 2;
    if len[num2[mid]] = flen then begin
      if used[num2[mid]] then
        l := mid + 1
      else begin
        res := mid;
        r := mid - 1;
      end;
    end
    else
      if len[num2[mid]] < flen then
        l := mid + 1
      else
        r := mid - 1;
  end;
  writeln(w[num2[res]]);
  used[num2[res]] := true;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n);
  for i := 1 to n do
    readln(w[i]);
  read(d);
  for i := 1 to n do begin
    w[i] := w[i] + d;
    len[i] := length(w[i]);
    num1[i] := i;
  end;
  sort1(1, n);
  for i := 1 to n do begin
    delete(w[i], len[i], 1);
    dec(len[i]);
  end;
  for i := 1 to n do
    num2[i] := i;
  sort2(1, n);
  sum := 0;
  for i := 1 to n do
    sum := sum + len[i];
  sum := sum + n div 2;
  slen := sum div (n div 2);
  for i := 1 to n do
    if not used[num1[i]] then begin
      find1(num1[i]);
      find2(slen - len[num1[i]] - 1);
    end;
end.