var n,m,i,j,k,l,r:Longint;
    h:char;
    a,b:array[1..8]of longint;
  begin
    for i:=1 to 8 do
     begin
       for j:=1 to 8 do
        begin
          read(h);
          if h='B' then begin inc(a[i]); inc(b[j]); end;
        end;
       readln;
     end;
    l:=0;
    r:=0;
    for i:=1 to 8 do
     begin
       if a[i]=8 then inc(l);
       if b[i]=8 then inc(r);
     end;
    if l+r=16 then writeln('8') else writeln(l+r);
  end.