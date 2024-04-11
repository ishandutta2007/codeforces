program task;

{$APPTYPE CONSOLE}
{$O-}

uses
  Math,
  SysUtils;

var s:string;
    cur,i,j:longint;
    curs,last:string;

function obr(var u:longint):string;
var cur:string;
begin
    cur:=s[u];
    while (s[u]<>'>') do begin
        inc(u);
        cur:=cur+s[u];
    end;
    inc(u);
    obr:=cur;
end;

begin
    //assign(input,'input.txt');
    readln(s);
    cur:=0;
    i:=1;
    last:='';
    curs:=obr(i);
    while true do begin
        if length(curs) = 4 then begin
            if length(last) = 4 then dec(cur);
            for j:=1 to 2*cur do
                write(' ');
            writeln(curs);
        end
        else begin
            if length(last) = 3 then inc(cur);
            for j:=1 to 2*cur do
                write(' ');
            writeln(curs);
        end;
        last:=curs;
        if i<=length(s) then curs:=obr(i) else break;
    end;
    halt(0);
end.