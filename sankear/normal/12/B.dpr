program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  s1, s2 : string;
  t : char;
  i : integer;

procedure sort(l, r : integer);
var x, t : char;
i, j : integer;
begin
  x := s1[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while s1[i] < x do
      inc(i);
    while s1[j] > x do
      dec(j);
    if i <= j then begin
      t := s1[i];
      s1[i] := s1[j];
      s1[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort(i, r);
  if j > l then
    sort(l, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(s1);
  readln(s2);
  sort(1, length(s1));
  i := 1;
  while (i <= length(s1)) and (s1[i] = '0') do
    inc(i);
  if i <= length(s1) then begin
    t := s1[1];
    s1[1] := s1[i];
    s1[i] := t;
  end;
  if s1 = s2 then
    write('OK')
  else
    write('WRONG_ANSWER');
end.