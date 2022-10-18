var a,b,c,d,k:longint;
  begin
    read(a,b,c,d);
    if (a=b) and (b=c) and (c=d) then writeln(3) else
    if ((a=b) and (b=c))
    or ((a=b) and (c=d))
    or ((a=b) and (b=d))
    or ((b=c) and (c=d))
    or ((a=d) and (c=b))
    or ((a=c) and (b=d))
    then writeln(2) else
    if (a=b) or (b=c) or (c=d) or (a=c) or (a=d) or (b=d) then writeln(1) else writeln(0);
  end.