program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s:string;
    l:longint;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(s);
    readln(l);
    if s = 'front' then begin
        if l = 1 then writeln('L') else writeln('R');
    end
    else
        if l = 1 then writeln('R') else writeln('L');
    halt(0);
end.