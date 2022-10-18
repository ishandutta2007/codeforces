var n,m,i,j,k,l,r:longint;
    a:array[1..2]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       if l=25 then inc(a[1]) else
       if l=50 then
        begin
          if a[1]>0 then
          begin
            dec(a[1]);
            inc(a[2]);
          end else
           begin
             writeln('NO');
             halt;
           end;
        end else
        begin
          if (a[2]>0) and (a[1]>0) then
           begin
             a[2]:=a[2]-1;
             a[1]:=a[1]-1;
           end else
          if (a[1]>2) then a[1]:=a[1]-3 else
           begin
             writeln('NO');
             halt;
           end;
        end;
     end;
    writeln('YES');
  end.