program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var t,i,k:longint;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(t);
    for i := 1 to t do begin
        readln(k);
        writeln((k+1)mod 2);
    end;
end.