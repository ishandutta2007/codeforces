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
    s1, s2 : string;
  end;

var
  n, k, i, j : integer;
  fl : boolean;
  s1, s2 : string;
  p : array[0..101] of tp;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z']) do
    read(c);
  while c in ['a'..'z'] do begin
    s := s + c;
    read(c);
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  k := 0;
  for i := 1 to n do begin
    gets(s1);
    gets(s2);
    fl := true;
    for j := 1 to k do
      if (s1 = p[j].s1) and (s2 = p[j].s2) then begin
        fl := false;
        break;
      end;
    if fl then begin
      inc(k);
      p[k].s1 := s1;
      p[k].s2 := s2;
    end;
  end;
  writeln(k);
end.