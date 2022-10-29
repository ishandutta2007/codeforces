{$APPTYPE CONSOLE}
uses
  Math,SysUtils;

var s:string;
    i,l,cur:longint;

begin
    l:=0;
    cur:=0;
    while not eof do begin
        readln(s);
        if (s[1]='+')or(s[1]='-')then begin
            if s[1]='+' then inc(cur) else dec(cur);
        end
        else begin
            i:=1;
            while (s[i]<>':') do inc(i);
            l:=l+cur*(length(s)-i)
        end;
    end;
    writeln(l);
    halt(0);
end.