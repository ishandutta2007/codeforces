uses math;
var p,l,r,n,n1,m,m1,k,k1,n2,m2,k2,n3,m3,k3:longint;
  begin
    read(n,m,k);
    n1:=n div 3;
    m1:=m div 3;
    k1:=k div 3;
    n2:=n mod 3;
    m2:=m mod 3;
    k2:=k mod 3;
    p:=max(n2,max(m2,k2));
    n3:=p-n2;
    m3:=p-m2;
    k3:=p-k2;
 
    if (n2=p) and (m2=p) then
     begin
       l:=(p-k2) div 3;
       r:=(p-k2) mod 3;
       if r>0 then inc(l);
       l:=min(l,k1);
       k2:=k2+(l*3);
       k1:=k1-l;
     end;
    if (n2=p) and (k2=p) then
     begin
       l:=(p-m2) div 3;
       r:=(p-m2) mod 3;
       if r>0 then inc(l);
       l:=min(l,m1);
       m2:=m2+(l*3);
       m1:=m1-l;
     end;
    if (m2=p) and (k2=p) then
     begin
       l:=(p-n2) div 3;
       r:=(p-n2) mod 3;
       if r>0 then inc(l);
       l:=min(l,n1);
       n2:=n2+(l*3);
       n1:=n1-l;
     end;
    p:=min(m2,min(k2,n2));
    writeln(k1+m1+n1+p);
  end.