program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var a,b,c:longint;

function obr:longint;
var s:string;
    cur,i:longint;
begin
    readln(s);
    cur:=0;
    for i:= 1 to length(s) do
        if (s[i]='a')or(s[i]='e')or(s[i]='i')or(s[i]='u')or(s[i]='o')then inc(cur);
    obr:=cur;
end;

begin
    a:=obr;
    b:=obr;
    c:=obr;
    if(a=5)and(b=7)and(c=5)then writeln('YES')else writeln('NO');
end.