var m,n,ss,kv,i,j,ec,k,rc,fc,x1,y1,z1:longint;
    ans,f:array[0..70,0..70,0..70] of longint;
    g:array[0..70,0..70] of longint;
    u,v:array[0..1000000] of longint;
begin
  readln(n,m,kv);
  filldword(f,sizeof(f) div 4,maxlongint);
  for ec:=1 to m do
    begin
      for i:=1 to n do
        for j:=1 to n do
          read(f[ec,i,j]);
      for k:=1 to n do
        for i:=1 to n do
          for j:=1 to n do
            if (i<>j) and (i<>k) and (j<>k) then
              if (f[ec,i,k]<>maxlongint) and (f[ec,k,j]<>maxlongint) then
                if f[ec,i,k]+f[ec,k,j]<f[ec,i,j] then
                  f[ec,i,j]:=f[ec,i,k]+f[ec,k,j];
    end;
  for i:=1 to n do
    for j:=1 to n do
      begin
        g[i,j]:=maxlongint;
        for k:=1 to m do
          if f[k,i,j]<g[i,j] then g[i,j]:=f[k,i,j];
      end;
  filldword(ans,sizeof(ans) div 4,maxlongint);
  for ss:=1 to n do
    begin
      rc:=1;
      fc:=1;
      u[rc]:=ss;
      v[rc]:=0;
      ans[ss,ss,0]:=0;
      while rc<=fc do
        begin
          if v[rc]<n then
            begin
              for i:=1 to n do
                if ans[ss,u[rc],v[rc]]+g[u[rc],i]<ans[ss,i,v[rc]+1] then
                  begin
                    ans[ss,i,v[rc]+1]:=ans[ss,u[rc],v[rc]]+g[u[rc],i];
                    inc(fc);
                    u[fc]:=i;
                    v[fc]:=v[rc]+1;
                  end;
            end;
          inc(rc);
        end;
    end;
  for i:=1 to kv do
    begin
      readln(x1,y1,z1);
      inc(z1);
      if z1>n then z1:=n;
      writeln(ans[x1,y1,z1]);
    end;
end.