program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type vector = record
    x, y : int64;
end;

var a, b, c : vector;
    i : longint;

function solve(a, b, c, d, e, f : int64) : boolean;
var a1, a2, b1, b2, c1, c2, det, det1, det2 : int64;
begin
    a1 := c;
    a2 := d;
    b1 := d;
    b2 := -c;
    c1 := e - a;
    c2 := f - b;
    det := a1 * b2 - b1 * a2;
    det1 := c1 * b2 - b1 * c2;
    det2 := c2 * a1 - c1 * a2;
    if (det = 0) and ((det1 <> 0) or (det2 <> 0)) then solve := false else begin
        if (det = 0) and (det1 = 0) and (det2 = 0) then solve := true else
            solve := (det1 mod det = 0) and (det2 mod det = 0);
    end;
    if (c = 0) and (d = 0) then Result := Result and (a = e) and (b = f);
end;

function rev(x : vector) : vector;
var y : vector;
begin
    y.x := x.y;
    y.y := -x.x;
    rev := y;
end;

begin
    readln(a.x, a.y);
    readln(b.x, b.y);
    readln(c.x, c.y);
    for i := 1 to 4 do begin
        a := rev(a);
        if solve(a.x, a.y, c.x, c.y, b.x, b.y) then begin
            writeln('YES');
            halt(0);
        end;
    end;
    writeln('NO');
    halt(0);
end.