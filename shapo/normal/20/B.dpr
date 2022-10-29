program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var a,b,c:extended;
    dsq:extended;

begin
    readln(a,b,c);
    if a < 0 then begin
        a:=-a;
        b:=-b;
        c:=-c;
    end;
    if a=0 then begin
        if b=0 then begin
            if c=0 then writeln(-1) else writeln(0);
        end
        else begin
            writeln(1);
            writeln(-c/b:0:10);
        end;
    end
    else begin
        dsq:=b*b-4*a*c;
        if dsq=0 then begin
            writeln(1);
            writeln(-b/(2*a):0:10);
        end
        else
            if dsq<0 then writeln(0) else begin
                writeln(2);
                writeln((-b-sqrt(dsq))/(2*a):0:10);
                writeln((-b+sqrt(dsq))/(2*a):0:10);
            end;
    end;
    halt(0);
end.