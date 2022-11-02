var n,i,ans,rc,fc,j:longint;
    x,y,use,u:array[0..10000] of longint;
begin
  readln(n);
  for i:=1 to n do
    readln(x[i],y[i]);
  ans:=-1;
  fillchar(use,sizeof(use),0);
  for i:=1 to n do
    if use[i]=0 then
      begin
        inc(ans);
        rc:=1;
        fc:=1;
        u[rc]:=i;
        use[i]:=1;
        while rc<=fc do
          begin
            for j:=1 to n do
              if (use[j]=0) and ((x[u[rc]]=x[j]) or (y[u[rc]]=y[j])) then
                begin
                  inc(fc);
                  u[fc]:=j;
                  use[j]:=1;
                end;
            inc(rc);
          end;
      end;
  writeln(ans);
end.