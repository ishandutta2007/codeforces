program task;

{$APPTYPE CONSOLE}
{$O+}

uses
  Math,
  SysUtils;

var a,b,x1,y1,x2,y2:int64;
    px,py,tx,ty,res:int64;

procedure obr(a,b,c,d:int64;var e,f:int64);
var k,l:int64;
begin
    k:=d-c;
    l:=d+c;
    if (k<0) then e := k div(2*b)
    else e:=k div (2*b)+1;
    if l < 0 then f := l div (2*a)
    else f:=l div (2*a)+1;
end;

begin
    readln(a,b,x1,y1,x2,y2);
    obr(a,b,x1,y1,px,py);
    obr(a,b,x2,y2,tx,ty);
    res:=max(abs(tx-px),abs(ty-py));
    writeln(res);
    halt(0);
end.