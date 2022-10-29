var n,i,a,b,res:longint;
begin
    res:=0;
    readln(n,a,b);
    for i:=1 to n do
        if (i>a)and(i+b>=n) then inc(res);
    writeln(res);
    halt(0);
end.