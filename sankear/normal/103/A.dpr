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
  len = 4;
  base = round(1e4);

type
  tl = array[0..10001] of integer;

var
  n, i : integer;
  ans, one, cur : tl;
  a : array[0..101] of integer;

procedure inttolong(var a : tl; b : int64);
begin
  if b = 0 then begin
    a[0] := 1;
    a[1] := 0;
    exit;
  end;
  a[0] := 0;
  while b > 0 do begin
    inc(a[0]);
    a[a[0]] := b mod base;
    b := b div base;
  end;
end;

procedure sum(var a, b : tl);
var ost, i : integer;
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
    ost := a[i] div base;
    a[i] := a[i] mod base;
  end;
  if ost > 0 then begin
    inc(a[0]);
    a[a[0]] := ost;
  end;
end;

procedure print(var a : tl);
var p, i, j : integer;
begin
  write(a[a[0]]);
  for i := a[0] - 1 downto 1 do begin
    p := 1;
    for j := 1 to len - 1 do begin
      p := p * 10;
      if a[i] < p then
        write(0);
    end;
    write(a[i]);
  end;
  writeln;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    read(a[i]);
    dec(a[i]);
  end;
  inttolong(ans, 0);
  inttolong(one, 1);
  for i := 1 to n do begin
    inttolong(cur, int64(a[i]) * i);
    sum(ans, cur);
    sum(ans, one);
  end;
  print(ans);
end.