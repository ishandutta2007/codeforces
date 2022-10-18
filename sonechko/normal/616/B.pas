var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       l:=maxlongint;
       for j:=1 to m do
        begin
          read(k);
          if k<l then l:=k;
        end;
       if l>ans then ans:=l;
     end;
    writeln(ans);
  end.