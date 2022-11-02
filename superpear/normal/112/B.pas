var n,x,y:longint;
begin
  readln(n,x,y);
  n:=n div 2;
  if (n=x) and (n=y) then writeln('NO') else
    if (n=x) and (n+1=y) then writeln('NO') else
      if (n+1=x) and (n=y) then writeln('NO') else
        if (n+1=x) and (n+1=y) then writeln('NO') else
          writeln('YES');
end.