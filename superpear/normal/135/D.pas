var m,n,i,j,ans,e,p,xc,yc,rc,fc,o,flag,v,tot:longint;
    vi,vj:array[0..10] of longint;
    a,b:array[0..2000,0..2000] of longint;
    x,y,xe,ye:array[0..4000000] of longint;
    ch:char;

begin
  readln(m,n);
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(ch);
          a[i,j]:=ord(ch)-48;
        end;
      readln;
    end;
  ans:=0;
  for i:=1 to m-1 do
    for j:=1 to n-1 do
      if (a[i,j]+a[i,j+1]+a[i+1,j]+a[i+1,j+1]=4) then ans:=4;
  tot:=2;
  vi[1]:=-1;vj[1]:=-1;
  vi[2]:=-1;vj[2]:=0;
  vi[3]:=-1;vj[3]:=1;
  vi[4]:=0;vj[4]:=-1;
  vi[5]:=0;vj[5]:=1;
  vi[6]:=1;vj[6]:=-1;
  vi[7]:=1;vj[7]:=0;
  vi[8]:=1;vj[8]:=1;
  fillchar(b,sizeof(b),0);
  for i:=1 to m do
    for j:=1 to n do
      if (a[i,j]=0) and (b[i,j]=0) then
        begin
          b[i,j]:=1;
          rc:=1;
          fc:=1;
          x[1]:=i;y[1]:=j;
          while rc<=fc do
            begin
              for e:=1 to 8 do
                begin
                  xc:=x[rc]+vi[e];
                  yc:=y[rc]+vj[e];
                  if (xc>=1) and (xc<=m) and (yc>=1) and (yc<=n) then
                    if (a[xc,yc]=0) and (b[xc,yc]=0) then
                      begin
                        inc(fc);
                        b[xc,yc]:=1;
                        x[fc]:=xc;y[fc]:=yc;
                      end;
                end;
              inc(rc);
            end;
          flag:=1;
          for e:=1 to fc do
            if (x[e]=1) or (x[e]=m) or (y[e]=1) or (y[e]=n) then
              begin
                flag:=0;
                break;
              end;
          if flag=1 then
            begin
              inc(tot);
              o:=0;
              for e:=1 to fc do
                for p:=1 to 8 do
                  begin
                    xc:=x[e]+vi[p];
                    yc:=y[e]+vj[p];
                    if (a[xc,yc]=1) and (b[xc,yc]<>tot) then
                      begin
                        b[xc,yc]:=tot;
                        inc(o);
                        xe[o]:=xc;ye[o]:=yc;
                      end;
                  end;
              for e:=1 to o do
                begin
                  v:=0;
                  if b[xe[e]-1,ye[e]]=tot then inc(v);
                  if b[xe[e],ye[e]-1]=tot then inc(v);
                  if b[xe[e],ye[e]+1]=tot then inc(v);
                  if b[xe[e]+1,ye[e]]=tot then inc(v);
                  if v<>2 then
                    begin
                      flag:=0;
                      break;
                    end;
                end;
              if flag=1 then
                begin
                  rc:=1;
                  fc:=1;
                  x[rc]:=xe[1];y[rc]:=ye[1];
                  b[xe[1],ye[1]]:=1;
                  while rc<=fc do
                    begin
                      for e:=1 to 8 do
                        begin
                          xc:=x[rc]+vi[e];
                          yc:=y[rc]+vj[e];
                          if (xc>=1) and (xc<=m) and (yc>=1) and (yc<=n) then
                            if b[xc,yc]=tot then
                              begin
                                inc(fc);
                                b[xc,yc]:=1;
                                x[fc]:=xc;
                                y[fc]:=yc;
                              end;
                        end;
                      inc(rc);
                    end;
                  if fc=o then
                    if o>ans then ans:=o;
                end;
            end;
        end;
  writeln(ans);
end.