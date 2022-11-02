var n,k,i,j,rc,fc:longint;
    a,flag,ans:array[0..2,0..120000] of longint;
    ch:char;
    x,y:array[0..10000000] of longint;

begin
  readln(n,k);
  for i:=1 to 2 do
    begin
      for j:=1 to n do
        begin
          read(ch);
          if ch='-' then a[i,j]:=0 else a[i,j]:=1;
        end;
      readln;
    end;
  filldword(ans,sizeof(ans) div 4,maxlongint);
  ans[1,1]:=0;
  rc:=1;
  fc:=1;
  x[rc]:=1;y[rc]:=1;
  fillchar(flag,sizeof(flag),0);
  while rc<=fc do
    begin
      flag[x[rc],y[rc]]:=0;
      if (a[x[rc],y[rc]]=0) and (ans[x[rc],y[rc]]<y[rc]) then
        begin
          if y[rc]+k>n then
            begin
              writeln('YES');
              halt;
            end;
          if ans[x[rc],y[rc]]+1<ans[3-x[rc],y[rc]+k] then
            begin
              ans[3-x[rc],y[rc]+k]:=ans[x[rc],y[rc]]+1;
              if flag[3-x[rc],y[rc]+k]=0 then
                begin
                  flag[3-x[rc],y[rc]+k]:=1;
                  inc(fc);
                  x[fc]:=3-x[rc];
                  y[fc]:=y[rc]+k;
                end;
            end;
          if ans[x[rc],y[rc]]+1<ans[x[rc],y[rc]+1] then
            begin
              ans[x[rc],y[rc]+1]:=ans[x[rc],y[rc]]+1;
              if flag[x[rc],y[rc]+1]=0 then
                begin
                  flag[x[rc],y[rc]+1]:=1;
                  inc(fc);
                  x[fc]:=x[rc];
                  y[fc]:=y[rc]+1;
                end;
            end;
          if (y[rc]>1) and (ans[x[rc],y[rc]]+1<ans[x[rc],y[rc]-1]) then
            begin
              ans[x[rc],y[rc]-1]:=ans[x[rc],y[rc]]+1;
              if flag[x[rc],y[rc]-1]=0 then
                begin
                  flag[x[rc],y[rc]-1]:=1;
                  inc(fc);
                  x[fc]:=x[rc];
                  y[fc]:=y[rc]-1;
                end;
            end;
        end;
      inc(rc);
    end;
  writeln('NO');
end.