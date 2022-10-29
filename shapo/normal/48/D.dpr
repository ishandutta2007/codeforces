program Project2;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var n, i, cur : integer;
    count, a, res : array[0..100000] of integer;

begin
    fillchar(count, sizeof(count), 0);
    fillchar(res, sizeof(res), 0);
    readln(n);
    for i := 1 to n do begin
       read(cur);
       a[i] := cur;
       inc(count[cur]);
    end;
    readln;
    cur := 100000;
    repeat
        while (count[cur] = 0) and (cur > 0) do dec(cur);
        if cur > 0 then begin
           i := cur;
            if count[cur] = 1 then dec(cur);
            while (i > 0) and (count[i] <> 0) do begin
                dec(count[i]);
                inc(res[i]);
               dec(i);
            end;
            if (i > 0) and (count[i] = 0) then begin
               writeln('-1');
               halt(0);
            end;
        end;
    until cur = 0;
    writeln(res[1]);
    for i := 1 to n do begin
       write(res[a[i]], ' ');
       dec(res[a[i]]);
    end;
end.