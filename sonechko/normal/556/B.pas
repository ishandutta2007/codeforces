var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n);
    ans:=0;
    for i:=1 to n do
     begin
       read(k);
       if (i mod 2=1) then
        begin
          if (k<i-1) then l:=(i-1)-k else l:=((n-1)-k)+i;
          if i=1 then ans:=l;
          //writeln(l);
          if ans<>l then begin writeln('No'); halt; end;
        end else
        begin
          if (k>i-1) then l:=k-(i-1) else l:=k+((n)-(i-1));
          //writeln(l);
          if ans<>l then begin writeln('No'); halt; end;
        end;
     end;
    writeln('Yes');
  end.