program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  a, b: array [1..3] of boolean;
  t, i: integer;
begin
  for i := 1 to 3 do begin
    Read(t);
    a[i] := t = 1;
  end;
  for i := 1 to 3 do begin
    Read(t);
    b[i] := t = 1;
  end;
  for i := 1 to 3 do
    a[i] := not a[i];

  for i := 1 to 3 do begin
    if a[i] <> b[i] then begin
      WriteLn('YES');
      exit;
    end;
  end;
  WriteLn('NO');
end.