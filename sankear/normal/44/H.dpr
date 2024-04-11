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
  n, i : integer;
  ans : int64;
  s : string;
  a : array[0..51] of integer;
  d : array[0..51, 0..10] of int64;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['0'..'9']) do
    read(c);
  while c in ['0'..'9'] do begin
    s := s + c;
    read(c);
  end;
end;

procedure solve(b1 : integer);
var i, j, z : integer;
begin
  for i := 1 to n do
    for j := 0 to 9 do
      d[i, j] := 0;
  d[1, b1] := 1;
  for i := 2 to n do
    for j := 0 to 9 do begin
      z := j + a[i];
      d[i, z div 2] := d[i, z div 2] + d[i - 1, j];
      if z mod 2 = 1 then
        d[i, z div 2 + 1] := d[i, z div 2 + 1] + d[i - 1, j];
    end;
  for i := 0 to 9 do
    ans := ans + d[n, i];
end;

function good() : boolean;
var i, j : integer;
begin
  result := true;
  for i := 2 to n do begin
    j := a[i - 1] + a[i];
    if j mod 2 = 0 then begin
      if a[i] <> j div 2 then begin
        result := false;
        exit;
      end;
    end
    else begin
      if (a[i] <> j div 2) and (a[i] <> j div 2 + 1) then begin
        result := false;
        exit;
      end;
    end;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  gets(s);
  n := length(s);
  for i := 1 to n do
    a[i] := ord(s[i]) - ord('0');
  ans := 0;
  for i := 0 to 9 do
    solve(i);
  if good() then
    ans := ans - 1;
  writeln(ans);
end.