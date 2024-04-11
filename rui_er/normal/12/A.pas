var
    a,b,c,d,e,f,g,h,i:char;
begin
    readln(a,b,c);
    readln(d,e,f);
    readln(g,h,i);
    if (a=i) and (b=h) and (c=g) and (d=f)
        then writeln('YES') else writeln('NO');
end.