var n,k,bigp,i,tot,ans,rc,fc,p:longint;
    x,y,last,vis,pre,u:array[0..500000] of longint;
begin
  readln(n,k,bigp);
  for i:=1 to k do
    begin
      readln(x[i],y[i]);
      x[i+k]:=y[i];
      y[i+k]:=x[i];
    end;
  k:=k*2;
  fillchar(last,sizeof(last),0);
  for i:=1 to k do
    begin
      pre[i]:=last[x[i]];
      last[x[i]]:=i;
    end;
  fillchar(vis,sizeof(vis),0);
  tot:=0;
  ans:=1;
  for i:=1 to n do
    if vis[i]=0 then
      begin
        vis[i]:=1;
        rc:=1;
        fc:=1;
        u[rc]:=i;
        inc(tot);
        while rc<=fc do
          begin
            p:=last[u[rc]];
            while p>0 do
              begin
                if vis[y[p]]=0 then
                  begin
                    inc(fc);
                    u[fc]:=y[p];
                    vis[y[p]]:=1;
                  end;
                p:=pre[p];
              end;
            inc(rc);
          end;
        ans:=int64(ans)*fc mod bigp;
      end;
  if tot>=2 then
    for i:=1 to tot-2 do
      ans:=int64(ans)*n mod bigp
  else
    ans:=1 mod bigp;

  writeln(ans);
end.