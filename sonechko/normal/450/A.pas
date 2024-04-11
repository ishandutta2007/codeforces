var n,m,i,j,k,s,l,r:longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(k);
       l:=k div m;
       if k mod m<>0 then inc(l);
       if l>=s then begin s:=l; r:=i; end;
     end;
    writeln(r);
  end.