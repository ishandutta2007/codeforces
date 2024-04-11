program task;

{$APPTYPE CONSOLE} {$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

var k, x, i, a, b, md, pp : longint;
    s : string;

begin
    readln(a, b, md);
    if md = 1 then writeln(2) else begin
        x := (1000 * 1000 * 1000) mod md;
        pp := 0;
        a := min(a, md);
        for i := 1 to a do begin
            pp := (pp + x) mod md;
            if ((md - pp) mod md >= b + 1) then begin
                writeln(1);
                s := inttostr(i);
                k := 9 - length(s);
                while (k > 0) do begin
                    write('0');
                    dec(k);
                end;
                writeln(s);
                halt(0);
            end;
        end;
        writeln(2);
    end;
    halt(0);
end.