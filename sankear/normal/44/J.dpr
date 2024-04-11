program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q-}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, i, j : integer;
  fl : boolean;
  z : char;
  usev : array[0..1001, 0..1001] of boolean;
  used : array['a'..'d'] of boolean;
  a : array[0..1001, 0..1001] of char;
  b1, b2 : array[0..1001, 0..1001] of integer;

procedure getc(var c : char);
begin
  read(c);
  while not (c in ['.', 'w', 'b']) do
    read(c);
end;

function can(x, y, t : integer) : boolean;
begin
  result := true;
  if t = 1 then begin
    if (a[x - 1, y] = 'b') and (b2[x - 1, y] < 2) then
      result := false;
    if (a[x + 1, y] = 'b') and (b2[x + 1, y] < 2) then
      result := false;
  end
  else begin
    if (a[x, y - 1] = 'b') and (b1[x, y - 1] < 2) then
      result := false;
    if (a[x, y + 1] = 'b') and (b1[x, y + 1] < 2) then
      result := false;
  end;
end;

procedure calc(x, y, t : integer);
begin
  if t = 1 then begin
    if a[x - 1, y] = 'b' then
      dec(b1[x - 1, y]);
    if a[x + 1, y] = 'b' then
      dec(b1[x + 1, y]);
  end
  else begin
    if a[x, y - 1] = 'b' then
      dec(b2[x, y - 1]);
    if a[x, y + 1] = 'b' then
      dec(b2[x, y + 1]);
  end;
end;

procedure check(x, y : integer);
var i, j : integer;
begin
  for i := -1 to 1 do
    for j := -1 to 1 do
      if (usev[x + i, y + j]) and (a[x + i, y + j] in ['a'..'d']) then
        used[a[x + i, y + j]] := true;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to n do
    for j := 1 to m do
      getc(a[i, j]);
  for i := 1 to n do
    for j := 1 to m do
      if a[i, j] = 'b' then begin
        if a[i - 1, j] = 'w' then
          inc(b1[i, j]);
        if a[i + 1, j] = 'w' then
          inc(b1[i, j]);
        if a[i, j - 1] = 'w' then
          inc(b2[i, j]);
        if a[i, j + 1] = 'w' then
          inc(b2[i, j]);
      end;
  for i := 1 to n do
    for j := 1 to m do
      if (a[i, j] = 'b') and (b1[i, j] < 2) and (b2[i, j] < 2) then begin
        writeln('NO');
        halt(0);
      end;
  for i := 1 to n do
    for j := 1 to m do
      if (not usev[i, j]) and (a[i, j] = 'b') then begin
        if (not usev[i - 1, j]) and (not usev[i + 1, j]) and (a[i - 1, j] = 'w') and (a[i + 1, j] = 'w') then begin
          fl := can(i - 1, j, 2) and can(i + 1, j, 2);
          if fl then begin
            calc(i - 1, j, 2);
            calc(i + 1, j, 2);
            for z := 'a' to 'd' do
              used[z] := false;
            check(i - 1, j);
            check(i, j);
            check(i + 1, j);
            for z := 'a' to 'd' do
              if not used[z] then begin
                usev[i - 1, j] := true;
                usev[i, j] := true;
                usev[i + 1, j] := true;
                a[i - 1, j] := z;
                a[i, j] := z;
                a[i + 1, j] := z;
                break;
              end;
            continue;
          end;
        end;
        if (not usev[i, j - 1]) and (not usev[i, j + 1]) and (a[i, j - 1] = 'w') and (a[i, j + 1] = 'w') then begin
          fl := can(i, j - 1, 1) and (can(i, j + 1, 1));
          if fl then begin
            calc(i, j - 1, 1);
            calc(i, j + 1, 1);
            for z := 'a' to 'd' do
              used[z] := false;
            check(i, j - 1);
            check(i, j);
            check(i, j + 1);
            for z := 'a' to 'd' do
              if not used[z] then begin
                usev[i, j - 1] := true;
                usev[i, j] := true;
                usev[i, j + 1] := true;
                a[i, j - 1] := z;
                a[i, j] := z;
                a[i, j + 1] := z;
                break;
              end;
            continue;
          end;
        end;
        writeln('NO');
        halt(0);
      end;
  for i := 1 to n do
    for j := 1 to m do
      if ((a[i, j] = 'w') or (a[i, j] = 'b')) and (not usev[i, j]) then begin
        writeln('NO');
        halt(0);
      end;
  writeln('YES');
  for i := 1 to n do begin
    for j := 1 to m do
      write(a[i, j]);
    writeln;
  end;
end.