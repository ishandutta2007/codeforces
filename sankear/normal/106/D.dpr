program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    ch : char;
    len : integer;
  end;

var
  n, m, k, x, y, i, j, z : integer;
  fl : boolean;
  a : array[0..1001, 0..1001] of char;
  sum1, sum2 : array[0..1001, 0..1001] of integer;
  p : array[0..100001] of tp;
  used : array[0..27] of boolean;

procedure getch(var ch : char);
begin
  read(ch);
  while not (ch in ['#', '.', 'A'..'Z']) do
    read(ch);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to n do
    for j := 1 to m do
      getch(a[i, j]);
  read(k);
  for i := 1 to k do begin
    getch(p[i].ch);
    read(p[i].len);
  end;
  for i := 1 to n do
    for j := 1 to m do begin
      sum1[i, j] := sum1[i, j - 1];
      if a[i, j] = '#' then
        inc(sum1[i, j]);
    end;
  for i := 1 to m do
    for j := 1 to n do begin
      sum2[i, j] := sum2[i, j - 1];
      if a[j, i] = '#' then
        inc(sum2[i, j]);
    end;
  for i := 1 to n do
    for j := 1 to m do
      if a[i, j] in ['A'..'Z'] then begin
        fl := true;
        x := i;
        y := j;
        for z := 1 to k do begin
          if p[z].ch = 'N' then begin
            if x - p[z].len < 1 then begin
              fl := false;
              break;
            end;
            if sum2[y, x] - sum2[y, x - p[z].len - 1] > 0 then begin
              fl := false;
              break;
            end;
            x := x - p[z].len;
            continue;
          end;
          if p[z].ch = 'S' then begin
            if x + p[z].len > n then begin
              fl := false;
              break;
            end;
            if sum2[y, x + p[z].len] - sum2[y, x - 1] > 0 then begin
              fl := false;
              break;
            end;
            x := x + p[z].len;
            continue;
          end;
          if p[z].ch = 'W' then begin
            if y - p[z].len < 1 then begin
              fl := false;
              break;
            end;
            if sum1[x, y] - sum1[x, y - p[z].len - 1] > 0 then begin
              fl := false;
              break;
            end;
            y := y - p[z].len;
            continue;
          end;
          if y + p[z].len > m then begin
            fl := false;
            break;
          end;
          if sum1[x, y + p[z].len] - sum1[x, y - 1] > 0 then begin
            fl := false;
            break;
          end;
          y := y + p[z].len;
        end;
        if fl then
          used[ord(a[i, j]) - ord('A') + 1] := true;
      end;
  fl := true;
  for i := 1 to 26 do
    if used[i] then begin
      fl := false;
      break;
    end;
  if fl then begin
    writeln('no solution');
    halt;
  end;
  for i := 1 to 26 do
    if used[i] then
      write(chr(ord('A') + i - 1));
  writeln;
end.