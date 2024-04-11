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
    s : string;
    t, num : integer;
  end;

var
  n, i, j : integer;
  t : tp;
  s : string;
  p : array[0..101] of tp;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z', 'A'..'Z']) do
    read(c);
  while c in ['a'..'z', 'A'..'Z'] do begin
    s := s + c;
    read(c);
  end;
end;

function less(var a, b : tp) : boolean;
begin
  result := (a.t < b.t) or ((a.t = b.t) and (a.num < b.num));
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    gets(p[i].s);
    gets(s);
    p[i].num := i;
    if s = 'rat' then
      p[i].t := 1
    else
      if s = 'woman' then
        p[i].t := 2
      else
        if s = 'child' then
          p[i].t := 2
        else
          if s = 'man' then
            p[i].t := 3
          else
            p[i].t := 4;
  end;
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if less(p[j], p[i]) then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  for i := 1 to n do
    writeln(p[i].s);
end.