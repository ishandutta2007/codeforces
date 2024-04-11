var s,t:ansistring;
    i,j,k,l1,r1,l2,r2,a,n,m,x,y,r:longint;
procedure c(b,q,res,last:longint);
 begin
   if (q=last) then
    begin
      if (b+n)=res then inc(r);
      exit;
    end;
   c(b+1,q+1,res,last);
   c(b-1,q+1,res,last);
 end;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(s) do
     if s[i]='+' then inc(l1) else inc(r1);
    for i:=1 to length(t) do
     if t[i]='+' then inc(l2) else
     if t[i]='-' then inc(r2) else inc(k);
    if k=0 then
     begin
       if (l1=l2) and (r1=r2) then writeln('1.000000000') else writeln('0.000000000');
       halt;
     end;
    n:=l2-r2;
    c(0,0,(l1-r1), k);
    m:=1;
    for i:=1 to k do
     m:=m*2;
    writeln(r/m:0:9);
  end.