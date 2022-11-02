program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q-}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  hx = 200003;

type
  ts = array[0..1000001] of char;

var
  alen, blen, k, i : integer;
  hs : int64;
  a, b : ts;
  p : array[0..1000001] of integer;
  pow, l, r : array[0..1000001] of int64;

procedure gets(var s : ts; var len : integer);
var c : char;
begin
  len := 0;
  read(c);
  while not (c in ['a'..'z']) do
    read(c);
  while c in ['a'..'z'] do begin
    inc(len);
    s[len] := c;
    read(c);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  gets(a, alen);
  gets(b, blen);
  pow[0] := 1;
  for i := 1 to alen do
    pow[i] := pow[i - 1] * hx;
  for i := 1 to alen do
    l[i] := l[i - 1] + pow[alen - i] * ord(a[i]);
  for i := alen downto 1 do
    r[i] := r[i + 1] + pow[alen - i] * ord(a[i]);
  hs := 0;
  for i := 1 to blen do
    hs := hs + pow[blen - i] * ord(b[i]);
  hs := hs * pow[1];
  k := 0;
  for i := 1 to alen do
    if l[i - 1] + r[i + 1] * pow[1] = hs then begin
      inc(k);
      p[k] := i;
    end;
  writeln(k);
  for i := 1 to k do
    write(p[i], ' ');
  writeln;
end.