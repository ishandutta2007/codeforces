program a;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, m, i, l, r, x : integer;
    s : string;

begin
    readln(n, m);
    l := 1;
    r := n;
    for i := 1 to m do begin
        readln(s);
        if s[8] = 'r' then begin
            delete(s, 1, 16);
            x := strtoint(s);
            l := max(l, x + 1);
        end
        else begin
            delete(s, 1, 15);
            x := strtoint(s);
            r := min(r, x - 1);
        end;
    end;
    if r < l then writeln(-1) else writeln(r - l + 1);
end.