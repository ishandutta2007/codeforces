var n,i,k:longint;
begin
    readln(n);
    i:=1;
    k:=1;
    while (k<n) do begin
        i:=i+1;
        k:=((i+1)*i)div 2;
    end;
    if k <> n then writeln('NO') else writeln('YES');
end.