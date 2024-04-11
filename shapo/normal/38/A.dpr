program Project3;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var n, a, b, i, res : integer;
    d : array[1..100] of integer;

begin
    readln(n);
    res := 0;
    for i := 2 to n do
        read(d[i]);
    readln;
    readln(a, b);
    for i := a + 1 to b do
        res := res + d[i];
    writeln(res);   
end.