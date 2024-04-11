program Project2;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var n, i : integer;
    a : array[1..100] of integer;
    ch, nch : array[0..100] of integer;

begin
    readln(n);
    for i := 1 to n do
        read(a[i]);
    readln;
    ch[0] := 0;
    nch[0] := 0;
    for i := 1 to n do
        if a[i] mod 2 = 0 then begin
            if nch[i - 1] <> 0 then nch[i] := nch[i - 1] + a[i] else nch[i] := 0;
            ch[i] := ch[i - 1] + a[i];
        end
        else begin
            nch[i] := max(ch[i - 1] + a[i], nch[i - 1]);
            if nch[i - 1] <> 0 then ch[i] := max(ch[i - 1], nch[i - 1] + a[i])
                else ch[i] := ch[i - 1];
        end;
    writeln(nch[n]);
end.