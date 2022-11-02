

var c : char;
    s : array[0 .. 1234567] of char;
    n, i, j, ans : longint;


begin
    read(c);
    while (c <> '0') and (c <> '1') do read(c);
    fillchar(s, sizeof(s), '0');
    n := 0;
    while (c = '0') or (c = '1') do begin
        inc(n);
        s[n] := c;
        read(c);
    end;
    i := n;
    ans := 0;
    while i > 0 do begin
        while (s[i] = '0') do dec(i);
        if (s[i] = '1') and ((i = 1) or (s[i - 1] <> '1')) then begin
            inc(ans);
            dec(i);
            continue;
        end;
        j := i;
        while (j > 0) and (s[j] = '1') do dec(j);
        i := j;
        while (j > 0) and (s[j] = '0') do dec(j);
        if (i = j) or (i - j > 1) then begin
            inc(ans);
            inc(ans);
            i := j;
            continue;
        end;
        s[j + 1] := '1';
        i := j + 1;
        inc(ans);
    end;
    writeln(ans);
end.