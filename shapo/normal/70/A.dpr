program candys;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const osn = 1000 * 1000 + 3;

var res, n, i : integer;

begin
    res := 1;
    readln(n);
    for i := 1 to n - 1 do
        res := (res * 3) mod osn;
    writeln(res);
end.