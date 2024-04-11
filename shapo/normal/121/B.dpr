program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n,i,k,l:longint;
    d:array[1..100000]of longint;
    c:char;

begin
    readln(n,k);
    for i:=1 to n do begin
        read(c);
        d[i]:=ord(c)-ord('0');
    end;
    readln;
    if (k<>0)and(n<>1) then begin
        l:=1;
        while true do begin
            while (l<>n) and((d[l]<>4)or(d[l+1]<>7))do inc(l);
            if l<>n then begin
                if(l mod 2=0) then begin
                    if (l<>1)and(d[l-1]=4)then begin
                        if k mod 2= 1 then begin
                            d[l]:=7;
                            d[l+1]:=7;
                        end;
                        k:=0;
                    end
                    else begin
                        d[l]:=7;
                        d[l+1]:=7;
                        dec(k);
                    end;
                end
                else begin
                    d[l]:=4;
                    d[l+1]:=4;
                    dec(k);
                end;
            end
            else break;
            if k<=0 then break;
        end;
    end;
    for i:= 1 to n do
        write(d[i]);
    halt(0);
end.