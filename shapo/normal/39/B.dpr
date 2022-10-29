program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  N, i, t, k, z: integer;
  a: array [1..10000] of integer;
begin
  ReadLn(N);
  z:=1;
  k := 0;
  for i := 1 to N do begin
    Read(t);
    if t = z then begin
      inc(k);
      a[k] := 2000 + i;
      inc(z);
    end;
  end;
  WriteLn(k);
  for i := 1 to k do
    Write(a[i], ' ');
end.