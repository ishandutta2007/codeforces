var n,m,i,j,k,ans,l,r:longint;
    s,t,d:string;
  begin
    readln(n);
    for i:=1 to n do
     begin
       readln(s);
       if (k=0) or (s=t) then begin inc(k); inc(l); t:=s; end else
       begin inc(r); d:=s; end;
     end;
    if l<r then writeln(d) else writeln(t);
  end.