
var ans, i, j, n, t : longint;
    a : array[0 .. 123456] of longint;
    
begin
    read(n, t);
    for i := 1 to n do begin
        read(a[i]);
    end;
    a[0] := 0;
    for i := 1 to n do a[i] := a[i - 1] + a[i];
    j := 1;
    ans := 0;
    for i := 1 to n do begin
        if j < i then j := i;
        while (j <= n) and (a[j] - a[i - 1] <= t) do inc(j);
        if ans < j - i then ans := j - i;
    end;
    writeln(ans);
end.