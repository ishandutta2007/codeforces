program A;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type domino = array[0..3] of integer;

var n, i, res, j : integer;
    s : string;
    sm : array[1..1000] of domino;
    used : array[1..1000] of boolean;

function ok(a, b : integer): boolean;
var i, j : integer;
begin
    ok := false;
    for i := 0 to 3 do begin
        j := 0;
        while (sm[a][(j + i) mod 4] = sm[b][j]) and (j <= 3) do inc(j);
        if j > 3 then ok := true;
    end;
end;

begin
    readln(n);
    res := 0;
    for i := 1 to n do begin
        readln(s);
        sm[i][0] := strtoint(s[1]);
        sm[i][1] := strtoint(s[2]);
        readln(s);
        sm[i][3] := strtoint(s[1]);
        sm[i][2] := strtoint(s[2]);
        if i <> n then readln(s);
    end;
    fillchar(used, sizeof(used), false);
    for i := 1 to n do begin
        if not used[i] then begin
            inc(res);
            for j := i + 1 to n do begin
                if not used[j] and ok(i, j) then used[j] := true;
            end;
        end;
    end;
    writeln(res);
end.