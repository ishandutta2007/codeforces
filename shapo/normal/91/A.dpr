program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s1, s2 : string;
    res, i, j, k, l : longint;
    used : array[1..26] of boolean;
    next : array[0..30000, 0..26] of longint;
    cur : longint;

begin
    fillchar(used, sizeof(used), false);
    readln(s1);
    readln(s2);
    res := 1;
    fillchar(next, sizeof(next), 100000);
    k := length(s1);
    for i :=1 to length(s1) do
        used[ord(s1[i]) - ord('a') + 1] := true;
    for i := 1 to length(s2) do
        if not used[ord(s2[i]) - ord('a') + 1] then res := -1;
    if res = 1 then begin
        s1 := s1 + s1 + s1[1];
        for i := 2 * k downto 0 do begin
            cur := ord(s1[i + 1]) - ord('a') + 1;
            for j := 1 to 26 do begin
                next[i, j] := next[i + 1, j];
                if j = cur then next[i, j] := i + 1;
            end;
        end;
        cur := 0;
        for i := 1 to length(s2) do begin
            l := ord(s2[i]) - ord('a') + 1;
            cur := next[cur, l];
            if cur > k then begin
                cur := cur - k;
                inc(res);
            end;
        end;
    end;
    writeln(res);
    halt(0);
end.