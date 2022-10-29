{$APPTYPE CONSOLE}
uses Math,SysUtils;
var n,i,x,y,a1,a2,a3,a4:longint;
    res:longint;
begin
    a1:=1000*1000+2;
    a3:=a1;
    a2:=-a1;
    a4:=a2;
    readln(n);
    for i := 1 to n do begin
        readln(x,y);
        if (y-x+1>a2) then a2:=y-x+1;
        if (y-x-1<a1) then a1:=y-x-1;
        if (y+x+1>a4) then a4:=y+x+1;
        if (y+x-1<a3) then a3:=y+x-1;
    end;
    res:=a2-a3+a4-a1;
    writeln(res);
    //readln;
end.