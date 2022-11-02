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
  ch : char;
  s, t : string;
  mf : array[1..9] of char = ('6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A');
  mg : array[1..4] of char = ('S', 'H', 'D', 'C');

procedure getch(var ch : char);
begin
  read(ch);
  while not (ch in ['0'..'9', 'A'..'Z']) do
    read(ch);
end;

procedure gets(var s : string);
var ch : char;
begin
  s := '';
  read(ch);
  while not (ch in ['0'..'9', 'A'..'Z']) do
    read(ch);
  while ch in ['0'..'9', 'A'..'Z'] do begin
    s := s + ch;
    read(ch);
  end;
end;

function f(ch : char) : integer;
var i : integer;
begin
  for i := 1 to 9 do
    if mf[i] = ch then begin
      result := i;
      exit;
    end;
end;

function g(ch : char) : integer;
var i : integer;
begin
  for i := 1 to 4 do
    if mg[i] = ch then begin
      result := i;
      exit;
    end;
end;

function good(a, b, c, d, e : integer) : boolean;
begin
  if b = a then begin
    if d <> a then begin
      result := true;
      exit;
    end;
    result := c > e;
    exit;
  end;
  if b <> d then begin
    result := false;
    exit;
  end;
  result := c > e;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  getch(ch);
  gets(s);
  gets(t);
  if good(g(ch), g(s[2]), f(s[1]), g(t[2]), f(t[1])) then
    writeln('YES')
  else
    writeln('NO');
end.