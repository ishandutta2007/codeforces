program a;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var p : array[1..4] of integer;
    cur : array[1..4] of integer;
    used : array[1..4] of boolean;
    aha, b, res, i : integer;
    sm : array[0..31415] of integer;

procedure pod;
var i : integer;
begin
    for i := aha to b do
        if (((i mod cur[1]) mod cur[2]) mod cur[3]) mod cur[4] = i then inc(sm[i]);
end;

procedure obr(u : integer);
var i : integer;
begin
    if u <> 5 then begin
        for i := 1 to 4 do
            if not used[i] then begin
                used[i] := true;
                cur[u] := p[i];
                obr(u + 1);
                used[i] := false;
            end;
    end
    else pod;
end;

begin
    readln(p[1], p[2], p[3], p[4], aha, b);
    fillchar(cur, sizeof(cur), 0);
    fillchar(used, sizeof(used), false);
    fillchar(sm, sizeof(sm), 0);
    res := 0;
    obr(1);
    for i := aha to b do
        if sm[i] >= 7 then inc(res);
    writeln(res);
end.