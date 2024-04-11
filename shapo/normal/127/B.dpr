program Project1;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 04000000}
{O+,R-,S-,Q-,I-}
{$O-,R+,S+,Q+,I+}

uses
  Math,SysUtils;

var n,i,cur,res:longint;
    num:array[1..100]of longint;

begin
    fillchar(num,sizeof(num),0);
    readln(n);
    for i := 1 to n do begin
        read(cur);
        inc(num[cur]);
    end;
    res:=0;
    for i := 1 to 100 do
        res:=(res+num[i] div 2);
    res:=res div 2;
    writeln(res);
    halt(0);
end.