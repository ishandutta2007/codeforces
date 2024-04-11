program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, ans, i : integer;
  cs : string;
  a : array[0..11] of integer;
  s : array[0..11] of string;
  used : array[0..36] of boolean;


procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['0'..'1']) do
    read(c);
  while c in ['0'..'1'] do begin
    s := s + c;
    read(c);
  end;
end;

procedure gen(x, y, z : integer);
var k, i, j : integer;
begin
  if y > z then begin
    cs := '';
    for i := 1 to n do
      if used[i] then
        cs := cs + s[1, i]
      else begin
        if s[1, i] = '0' then
          cs := cs + '1'
        else
          cs := cs + '0';
      end;
    for i := 2 to m do begin
      k := 0;
      for j := 1 to n do
        if s[i, j] = cs[j] then
          inc(k);
      if k <> a[i] then
        exit;
    end;
    inc(ans);
    exit;
  end;
  if z - y + 1 > n - x + 1 then
    exit;
  for i := x to n do begin
    used[i] := true;
    gen(i + 1, y + 1, z);
    used[i] := false;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to m do begin
    gets(s[i]);
    read(a[i]);
  end;
  ans := 0;
  gen(1, 1, a[1]);
  writeln(ans);
end.