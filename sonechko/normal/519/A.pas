var p:char;
    i,j,k,ans,l,r,n,m:longint;
  begin
    for i:=1 to 8 do
     begin
       for j:=1 to 8 do
        begin
          read(p);
          if p='Q' then inc(l,9);
          if p='R' then inc(l,5);
          if p='B' then inc(l,3);
          if p='N' then inc(l,3);
          if p='P' then inc(l,1);
          if p='q' then inc(r,9);
          if p='r' then inc(r,5);
          if p='b' then inc(r,3);
          if p='n' then inc(r,3);
          if p='p' then inc(r,1);
        end;
       readln;
     end;
    if l>r then writeln('White') else
    if r>l then writeln('Black') else writeln('Draw');
  end.