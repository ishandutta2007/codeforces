program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type
  tp = record
    a, b : char;
    c : integer;
  end;

var
  n, i, j, z, state, ans, res, num : integer;
  r : array[0..100001] of char;
  s1, s2, s : string;
  p : array[0..501] of tp;
  d : array['a'..'z', 'a'..'z'] of integer;

function f(x : integer) : char;
begin
  result := chr(ord('a') + x - 1);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(s1);
  readln(s2);
  readln(n);
  for i := 1 to n do begin
    readln(s);
    state := 1;
    p[i].a := #0;
    p[i].b := #0;
    p[i].c := 0;
    for j := 1 to length(s) do
      if s[j] = ' ' then
        inc(state)
      else begin
        if state = 1 then
          p[i].a := s[j];
        if state = 2 then
          p[i].b := s[j];
        if state = 3 then
          p[i].c := p[i].c * 10 + ord(s[j]) - ord('0');
      end;
  end;
  if length(s1) <> length(s2) then begin
    write(-1);
    halt(0);
  end;
  for i := 1 to 26 do begin
    for j := 1 to 26 do
      d[f(i), f(j)] := 1000000000;
    d[f(i), f(i)] := 0;
  end;
  for i := 1 to n do
    d[p[i].a, p[i].b] := min(d[p[i].a, p[i].b], p[i].c);
  for i := 1 to 26 do
    for j := 1 to 26 do
      for z := 1 to 26 do
        d[f(j), f(z)] := min(d[f(j), f(z)], d[f(j), f(i)] + d[f(i), f(z)]);
  ans := 0;
  for i := 1 to length(s1) do begin
    res := 1000000000;
    num := 0;
    for j := 1 to 26 do
      if d[s1[i], f(j)] + d[s2[i], f(j)] < res then begin
        res := d[s1[i], f(j)] + d[s2[i], f(j)];
        num := j;
      end;
    if res = 1000000000 then begin
      write(-1);
      halt(0);
    end;
    ans := ans + res;
    r[i] := f(num);
  end;
  writeln(ans);
  for i := 1 to length(s1) do
    write(r[i]);
end.