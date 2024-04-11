var n:longint;
begin
  readln(n);
  n:=n-10;
  if n<=0 then writeln(0) else
    if n<10 then writeln(4) else
      if n=11 then writeln(4) else
        if n=10 then writeln(15) else
          writeln(0);
end.