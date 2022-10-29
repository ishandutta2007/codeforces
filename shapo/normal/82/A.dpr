program cola;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, k : integer;
    n1, sp, l1 : int64;
    s : array[1..5] of string;

begin
    s[1] := 'Sheldon';
    s[2] := 'Leonard';
    s[3] := 'Penny';
    s[4] := 'Rajesh';
    s[5] := 'Howard';
    readln(n);
    n1 := n;
    sp := 0;
    l1 := 5;
    while (sp + l1 < n1) do begin
        sp := sp + l1;
        l1 := l1 * 2;
    end;
    n1 := n1 - sp - 1;
    l1 := l1 div 5;
    k := (n1 div l1) + 1;
    writeln(s[k]);
    halt(0);
end.