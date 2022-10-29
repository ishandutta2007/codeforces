program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

function ToKBase(val, base: integer): string;
begin
  Result:='';
  while val > 0 do begin
    Result := IntToStr(val mod base) + Result;
    val := val div base;
  end;
end;

var
  k, i, j: integer;
begin
  ReadLn(K);
  for i := 1 to k-1 do begin
    for j := 1 to k - 1 do
      Write(TokBase(i*j, k), ' ');
    WriteLn;
  end;
end.