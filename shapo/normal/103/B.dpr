program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, m, i : longint;
    sm : array[1..1000, 1..1000] of boolean;
    used, cc : array[1..1000] of boolean;
    a, b : longint;
    x : boolean;
    cycle : array[0..1000] of longint;

procedure DFS(u, v : longint);
var i, j : longint;
begin
    used[u] := true;
    inc(cycle[0]);
    cycle[cycle[0]] := u;
    for i := 1 to n do
        if sm[i, u] then begin
            if not used[i] then DFS(i, u) else begin
                if (i <> v) and not x then begin
                    x := true;
                    j := cycle[0];
                    while cycle[j] <> i do begin
                        cc[cycle[j]] := true;
                        dec(j);
                    end;
                    cc[cycle[j]] := true;
                end;
            end;
        end;
    dec(cycle[0]);
end;

procedure DFS1(u : longint);
var i : longint;
begin
    used[u] := true;
    for i := 1 to n do
        if sm[i, u] and not used[i] then
            if not (cc[i] and cc[u]) then DFS1(i);
end;

begin
    fillchar(sm, sizeof(sm), false);
    fillchar(used, sizeof(used), false);
    fillchar(cc, sizeof(cc), false);
    readln(n, m);
    for i := 1 to m do begin
        readln(a, b);
        sm[a, b] := true;
        sm[b, a] := true;
    end;
    x := false;
    DFS(1, 0);
    if not x then writeln('NO') else begin
        x := false;
        fillchar(used, sizeof(used), false);
        for i := 1 to n do
            if cc[i] then begin
                x := x or used[i];
                DFS1(i);
            end;
        for i := 1 to n do
	x := x or (not used[i]);
        if x then writeln('NO') else writeln('FHTAGN!');
    end;
    halt(0);
end.