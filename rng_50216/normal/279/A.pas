

const DX : array[0 .. 3] of integer = (1, 0, -1, 0);
      DY : array[0 .. 3] of integer = (0, 1, 0, -1);
      
var z : array[-1000 .. 1000, -1000 .. 1000] of longint;
    j, x, y, d, i, len : longint;

begin
    x := 0;
    y := 0;
    d := 0;    
    z[0][0] := 0;
    for i := 1 to 1000 do begin
        len := (i - 1) div 2 + 1;
        for j := 1 to len do begin
            x += DX[d];
            y += DY[d];
            z[x][y] := i - 1;
        end;
        d := (d + 1) and 3;
    end;
    read(x, y);
    writeln(z[x][y]);
end.