var n,m,k,l,r,a,b,newb,a1,b1,s:int64;
    i,j,newa:longint;
  begin
    s:=1000000000000000000;
    read(n,a,b);
    if a*b>=6*n then begin writeln(a*b); writeln(a,' ',b); halt; end;
    if a>b then begin r:=a; a:=b; b:=r; l:=1; end;
    for newa:=a to trunc(sqrt(6*n)) do
     begin
       newb:=(6*n)div newa;
       if (newa*newb<6*n) then inc(newb);
       if (newb<b) then continue;
       if (newa*newb<=s) then begin s:=newa*newb; a1:=newa; b1:=newb; end;
     end;
    writeln(a1*b1);
    if l=1 then writeln(b1,' ',a1) else writeln(a1,' ',b1);
  end.