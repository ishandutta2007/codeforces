uses math;
Var l,mx,x,y,r,u,c,ans,i,j,n,m:integer;
    a:array[0..1003,0..1003]of integer;
  begin
    read(n,m);
    r:=0;
    for i:=1 to n do
      for j:=1 to m do
       begin
         read(a[i,j]);
         r:=max(r,a[i,j]);
       end;
    ans:=min(a[1,1],a[1,m]);
    ans:=min(ans,a[n,m]);
    ans:=min(ans,a[n,1]);
    for i:=1 to n do
      for j:=i+1 to n do
        begin
          mx:=-1;
          for u:=1 to m do
            if (a[i,u]>ans)and(a[j,u]>ans) then
              begin
                x:=min(a[i,u],a[j,u]);
                y:=min(mx,x);
                if mx<>-1 then if ans<y then ans:=y;
                if mx=-1 then mx:=min(a[i,u],a[j,u])
                else mx:=max(mx,x);
              end;
        end;
    Writeln(ans);
  end.