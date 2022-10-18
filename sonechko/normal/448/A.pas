var a,b,a1,a2,a3,b1,b2,b3,n:Longint;
  begin
    read(a1,a2,a3,b1,b2,b3,n);
    a:=(a1+a2+a3)div 5;
    if (a1+a2+a3)mod 5<>0 then inc(a);
    b:=(b1+b2+b3)div 10;
    if (b1+b2+b3)mod 10<>0 then inc(b);
    if (a+b<=n) then writeln('YES') else writeln('NO');
  end.