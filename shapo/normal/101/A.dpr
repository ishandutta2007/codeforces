program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var s1, s2 : string;
    a : array[1..26] of longint;
    n1, i, m, cur, k, ind : longint;
    used : array[1..26] of boolean;

begin
    fillchar(a, sizeof(a), 0);
    readln(s1);
    readln(k);
    n1 := length(s1);
    s2 := '';
    for i := 1 to n1 do
        inc(a[ord(s1[i]) - ord('a') + 1]);
    m := 0;
    for i := 1 to 26 do
        if a[i] <> 0 then inc(m) else used[i] := true;
    cur := 0;
    ind := 1;
    for i := 1 to 26 do
        if (not used[i]) and (used[ind] or (a[i] < a[ind])) then ind := i;
    while (cur + a[ind] <= k) and not used[ind] do begin
        used[ind] := true;
        cur := cur + a[ind];
        ind := 1;
        for i := 1 to 26 do
            if (not used[i]) and (used[ind] or (a[i] < a[ind])) then ind := i;
        dec(m);
    end;
    writeln(m);
    for i := 1 to n1 do
        if not used[ord(s1[i]) - ord('a') + 1] then s2 := s2 + s1[i];
    writeln(s2);
    halt(0);
end.