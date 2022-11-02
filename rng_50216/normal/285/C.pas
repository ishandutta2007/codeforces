
var a : array[0 .. 423445] of longint;

procedure sort(l, r : longint);
var i, j, x, t : longint;
    begin
        i := l;
        j := r;
        x := a[random(r - l + 1) + l];
        while i <= j do begin
            while a[i] < x do inc(i);
            while a[j] > x do dec(j);
            if i <= j then begin
                t := a[i];
                a[i] := a[j];
                a[j] := t;
                inc(i);
                dec(j);
            end;
        end;
        if i < r then sort(i, r);
        if l < j then sort(l, j);
    end;
var n, i, d : longint;
    ans : int64;
    
begin
    randomize;
    read(n);
    for i := 1 to n do begin
        read(a[i]);
    end;
    sort(1, n);
    ans := 0;
    for i := 1 to n do begin
        d := i - a[i];
        if d < 0 then d := -d;
        ans := ans + d;
    end;
    writeln(ans);
end.