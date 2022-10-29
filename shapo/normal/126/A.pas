{$APPTYPE CONSOLE}
{$O+,R-,S-,Q-,I-}
uses
  Math,
  SysUtils;

var t0,t1,t2,x1,x2:int64;
    tm,t1m,y1:int64;
    i:int64;

function ok(a,b,c,d:int64):boolean;
var a1,a2:int64;
begin
    a1:=(t1*a+t2*b)*(c+d);
    a2:=(t1*c+t2*d)*(a+b);
    ok:=(a1<a2)or((a1=a2)and(a+b>c+d));
end;

begin
    readln(t1,t2,x1,x2,t0);
    if (t1=t2) then begin
        writeln(x1,' ',x2);
        halt(0);
    end;
    if (t1 = t0) then
        if (t2<>t0) or ((t2=t0) and (x1>=x2)) then begin
            writeln(x1,' ',0);
            halt(0);
        end;
    if (t2=t0)then
        if(t1<>t0)or((t1=t0)and(x2>=x1))then begin
            writeln(0,' ',x2);
            halt(0);
        end;
    tm:=0;
    t1m:=x2;
    i:=0;
    while(i<=x1)do begin
        y1:=(i*(t0-t1)+t2-t0-1)div(t2-t0);
        if (y1<=x2)and ok(i,y1,tm,t1m) then begin
            tm:=i;
            t1m:=y1;
        end;
        i:=i+1;
    end;
    writeln(tm,' ',t1m);
    halt(0);
end.