var n,m,i,j,k,l,r,x:longint;
  begin
    read(n);
    read(x);
    l:=x;
    r:=x;
    k:=0;
    for i:=2 to n do
     begin
       read(x);
       if x>l then begin inc(k); l:=x; end;
       if x<r then begin inc(k); r:=x; end;
     end;
    writeln(k);
  end.