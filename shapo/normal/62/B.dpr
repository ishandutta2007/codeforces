program b;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s, c : string;
    res : array[1..100000] of int64;
    l, r : array[1..26, 1..100000] of int64;
    n, k, i, j : integer;

procedure obr(s : string);
var i, j : integer;
    curc : integer;
    lc, rc : array[1..26] of integer;
begin
    fillchar(lc, sizeof(lc), 0);
    fillchar(rc, sizeof(rc), 0);
    for i := 1 to k do begin
        curc := ord(s[i]) - ord('a') + 1;
        lc[curc] := i;
        for j := 1 to 26 do
            if lc[j] <> 0 then l[j, i] := i - lc[j];
    end;
    for i := k downto 1 do begin
        curc := ord(s[i]) - ord('a') + 1;
        rc[curc] := i;
        for j := 1 to 26 do
            if rc[j] <> 0 then r[j, i] := rc[j] - i;
    end;
    for i := k + 1 to 100000 do
        for j := 1 to 26 do begin
            l[j, i] := l[j, i - 1] + 1;
            r[j, i] := 1000000;
        end;
end;

function ok(c : string) : int64;
var i, l1, curc : integer;
    cur, mx : int64;
begin
    l1 := length(c);
    cur := 0;
    for i := 1 to l1 do begin
        curc := ord(c[i]) - ord('a') + 1;
        mx := min(l[curc, i], r[curc, i]);
        if mx >= 1000000 then cur := cur + l1 else cur := cur + mx;
    end;
    ok := cur;
end;

begin
    for i := 1 to 100000 do
        for j := 1 to 26 do begin
            l[j, i] := 1000000;
            r[j, i] := 1000000;
        end;
    readln(n, k);
    readln(s);
    obr(s);
    for i := 1 to n do begin
        readln(c);
        res[i] := ok(c);
    end;
    for i := 1 to n do
        writeln(res[i]);
end.