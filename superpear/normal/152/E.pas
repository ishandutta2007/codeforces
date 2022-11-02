var m,n,k,i,j,x1,y1,rc,fc,xc,yc,ans,e1,e2,e3:longint;
    dat,imp,use:array[0..200,0..200] of longint;
    x,y,z:array[0..3000000] of longint;
    f,l1,l2,l3,l4:array[0..200,0..200,0..200] of longint;
    vi,vj:array[0..5] of longint;

procedure search(e1,e2,e3:longint);
  begin
    if (e1=0) or (e2=0) or (e3=0) then exit;
    use[e1,e2]:=1;
    if l3[e1,e2,e3]=0 then
      begin
        search(l1[e1,e2,e3],l2[e1,e2,e3],e3);
      end
    else
      begin
        search(l1[e1,e2,e3],l2[e1,e2,e3],l3[e1,e2,e3]);
        search(l1[e1,e2,e3],l2[e1,e2,e3],l4[e1,e2,e3]);
      end;
  end;

begin
  readln(m,n,k);
  for i:=1 to m do
    for j:=1 to n do
      read(dat[i,j]);
  fillchar(imp,sizeof(imp),0);
  for i:=1 to k do
    begin
      readln(x1,y1);
      imp[x1,y1]:=i;
    end;
  filldword(f,sizeof(f) div 4,maxlongint);
  fillchar(l1,sizeof(l1),0);
  fillchar(l2,sizeof(l2),0);
  fillchar(l3,sizeof(l3),0);
  fillchar(l4,sizeof(l4),0);
  rc:=1;
  fc:=0;
  for i:=1 to m do
    for j:=1 to n do
      if imp[i,j]<>0 then
        begin
          inc(fc);
          x[fc]:=i;
          y[fc]:=j;
          z[fc]:=1 shl (imp[i,j]-1);
          f[x[fc],y[fc],z[fc]]:=dat[i,j];
        end;
  vi[1]:=-1;vj[1]:=0;
  vi[2]:=0;vj[2]:=-1;
  vi[3]:=0;vj[3]:=1;
  vi[4]:=1;vj[4]:=0;
  while rc<=fc do
    begin
      for i:=1 to (1 shl k-1) do
        if (f[x[rc],y[rc],i]<>maxlongint) then
          if (f[x[rc],y[rc],z[rc]]+f[x[rc],y[rc],i]-dat[x[rc],y[rc]]<f[x[rc],y[rc],z[rc] or i]) then
            begin
              f[x[rc],y[rc],z[rc] or i]:=f[x[rc],y[rc],z[rc]]+f[x[rc],y[rc],i]-dat[x[rc],y[rc]];
              inc(fc);
              x[fc]:=x[rc];y[fc]:=y[rc];z[fc]:=z[rc] or i;
              l1[x[fc],y[fc],z[fc]]:=x[rc];
              l2[x[fc],y[fc],z[fc]]:=y[rc];
              l3[x[fc],y[fc],z[fc]]:=z[rc];
              l4[x[fc],y[fc],z[fc]]:=i;
            end;
      for i:=1 to 4 do
        begin
          xc:=x[rc]+vi[i];
          yc:=y[rc]+vj[i];
          if (xc>0) and (xc<=m) and (yc>0) and (yc<=n) then
            if dat[xc,yc]+f[x[rc],y[rc],z[rc]]<f[xc,yc,z[rc]] then
              begin
                f[xc,yc,z[rc]]:=dat[xc,yc]+f[x[rc],y[rc],z[rc]];
                inc(fc);
                x[fc]:=xc;y[fc]:=yc;z[fc]:=z[rc];
                l1[x[fc],y[fc],z[fc]]:=x[rc];
                l2[x[fc],y[fc],z[fc]]:=y[rc];
                l3[x[fc],y[fc],z[fc]]:=0;
                l4[x[fc],y[fc],z[fc]]:=0;
              end;
        end;
      inc(rc);
    end;
  ans:=maxlongint;
  for i:=1 to m do
    for j:=1 to n do
      if f[i,j,1 shl k-1]<ans then
        begin
          ans:=f[i,j,1 shl k-1];
          e1:=i;
          e2:=j;
          e3:=1 shl k-1;
        end;
  writeln(ans);
  fillchar(use,sizeof(use),0);
  search(e1,e2,e3);
  for i:=1 to m do
    begin
      for j:=1 to n do
        if use[i,j]=0 then write('.') else write('X');
      writeln;
    end;
end.