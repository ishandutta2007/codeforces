program solution;

{$APPTYPE CONSOLE}
{$O-,R+}

uses
  SysUtils,
  Math;

type
  tp = record
    x, y : integer;
  end;

var
  n, m, i, j : integer;
  fl : boolean;
  used : array[0..501] of boolean;
  p : array[0..501] of tp;
  len, num : array[0..501] of integer;

function dist(num1, num2, num3 : integer) : integer;
var d1, d2 : integer;
begin
  if p[num1].x = p[num2].x then
    d1 := abs(p[num1].y - p[num2].y)
  else
    d1 := abs(p[num1].x - p[num2].x);
  if p[num3].x = p[num2].x then
    d2 := abs(p[num3].y - p[num2].y)
  else
    d2 := abs(p[num3].x - p[num2].x);
  result := d1 + d2;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  randomize;
  read(n, m);
  for i := 1 to n do
    read(p[i].x, p[i].y);
  for i := 1 to m do
    read(len[i]);
  fl := true;
  for i := 1 to n do
    num[i] := -1;
  for i := 1 to m do
    used[i] := false;
  i := 3;
  while i <= n - 1 do begin
    for j := 1 to m do
      if (not used[j]) and (dist(i - 2, i - 1, i) = len[j]) then begin
        num[i - 1] := j;
        used[j] := true;
        break;
      end;
    if num[i - 1] = -1 then begin
      fl := false;
      break;
    end;
    i := i + 2;
  end;
  for i := 1 to m do
    if (not used[i]) and (dist(n - 1, n, 1) = len[i]) then begin
      num[n] := i;
      used[i] := true;
      break;
    end;
  if num[n] = -1 then
    fl := false;
  if fl then begin
    writeln('YES');
    for i := 1 to n do
      write(num[i], ' ');
    halt(0);
  end;
  fl := true;
  for i := 1 to n do
    num[i] := -1;
  for i := 1 to m do
    used[i] := false;
  i := 4;
  while i <= n do begin
    for j := 1 to m do
      if (not used[j]) and (dist(i - 2, i - 1, i) = len[j]) then begin
        num[i - 1] := j;
        used[j] := true;
        break;
      end;
    if num[i - 1] = -1 then begin
      fl := false;
      break;
    end;
    i := i + 2;
  end;
  for i := 1 to m do
    if (not used[i]) and (dist(n, 1, 2) = len[i]) then begin
      num[1] := i;
      used[i] := true;
      break;
    end;
  if num[1] = -1 then
    fl := false;
  if fl then begin
    writeln('YES');
    for i := 1 to n do
      write(num[i], ' ');
    halt(0);
  end;
  write('NO');
end.