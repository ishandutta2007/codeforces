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
  mp = round(1e9 + 7);

var
  t, k, ans, i, j, z, h : integer;
  l, r : array[0..1001] of string;
  d, dd : array[0..1001, -1..1001, -1..9] of integer;

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

function good(a : integer) : boolean; overload;
begin
  result := (a = 4) or (a = 7);
end;

function good(a : char) : boolean; overload;
begin
  result := (a = '4') or (a = '7');
end;

procedure add(var a : integer; b : integer);
begin
  a := a + b;
  while a >= mp do
    a := a - mp;
end;

procedure del(var a : integer; b : integer);
begin
  a := a - b;
  while a < 0 do
    a := a + mp;
end;

procedure doit(var s : string);
var len, i : integer;
begin
  len := length(s);
  i := len;
  while s[i] = '0' do
    dec(i);
  dec(s[i]);
  while i < len do begin
    inc(i);
    s[i] := '9';
  end;
end;

function sum(a, b, c, d, e : integer) : integer;
begin
  result := 0;
  if (b > c) or (d > e) then
    exit;
  add(result, dd[a, c, e]);
  del(result, dd[a, c, d - 1]);
  del(result, dd[a, b - 1, e]);
  add(result, dd[a, b - 1, d - 1]);
end;

function calc(var s : string) : integer;
var len, last, i : integer;
fl : boolean;
begin
  result := 0;
  len := length(s);
  last := 0;
  fl := false;
  for i := 1 to len do begin
    if fl then
      add(result, sum(len - i + 1, 0, k + 1, 0, ord(s[i]) - ord('0') - 1))
    else begin
      add(result, sum(len - i + 1, k + 1, k + 1, 0, ord(s[i]) - ord('0') - 1));
      if last > 0 then
        add(result, sum(len - i + 1, 1, k - i + last + 1, 0, ord(s[i]) - ord('0') - 1));
    end;
    if good(s[i]) then begin
      if (last > 0) and (i - last <= k) then
        fl := true;
      last := i;
    end;
  end;
  if fl then
    add(result, 1);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(t, k);
  for i := 1 to t do begin
    gets(l[i]);
    gets(r[i]);
  end;
  for i := 0 to 9 do
    if good(i) then
      d[1, 1, i] := 1
    else
      d[1, 0, i] := 1;
  for i := 1 to 1000 do
    for j := 0 to k + 1 do
      for z := 0 to 9 do
        if j <= k then begin
          for h := 0 to 9 do
            if good(h) then begin
              if j = 0 then
                add(d[i + 1, 1, h], d[i, j, z])
              else
                add(d[i + 1, k + 1, h], d[i, j, z]);
            end
            else begin
              if j = 0 then
                add(d[i + 1, 0, h], d[i, j, z])
              else
                if j < k then
                  add(d[i + 1, j + 1, h], d[i, j, z])
                else
                  add(d[i + 1, 0, h], d[i, j, z]);
            end;
        end
        else begin
          for h := 0 to 9 do
            add(d[i + 1, k + 1, h], d[i, j, z]);
        end;
  for i := 1 to 1001 do
    for j := 0 to k + 1 do
      for z := 0 to 9 do begin
        add(dd[i, j, z], dd[i, j, z - 1]);
        add(dd[i, j, z], dd[i, j - 1, z]);
        del(dd[i, j, z], dd[i, j - 1, z - 1]);
        add(dd[i, j, z], d[i, j, z]);
      end;
  for i := 1 to t do begin
    if l[i] = '1' then
      ans := calc(r[i])
    else begin
      doit(l[i]);
      ans := calc(r[i]) - calc(l[i]);
      while ans < 0 do
        ans := ans + mp;
    end;
    writeln(ans);
  end;
end.