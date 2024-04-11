program Project2;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var n1, m1, a1 : integer;
    n, m, a : int64;

begin
    readln(n1, m1, a1);
    n := n1;
    m := m1;
    a := a1;
    n := ((n - 1) div a + 1) * ((m - 1) div a + 1);
    writeln(n);
end.