
var x, y, n, m, i : longint;
    a, b, c : array[0 .. 123456] of longint;
    
begin
    read(n, m);
    for i := 1 to n do read(a[i]);
    b[1] := 1;
    for i := 2 to n do begin
        if a[i] <= a[i - 1] then b[i] := b[i - 1] + 1 else b[i] := 1;
    end;
    c[n] := 1;
    for i := n - 1 downto 1 do begin
        if a[i] <= a[i + 1] then c[i] := c[i + 1] + 1 else c[i] := 1;        
    end;
    for i := 1 to m do begin
        read(x, y);
        if (x + c[x] > y) or (y - b[y] < x) or (x + c[x] > y - b[y]) then writeln('Yes') else writeln('No');
    end;
end.