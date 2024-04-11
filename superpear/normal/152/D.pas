var m,n,i,j,ic,tot,swapflag,rc,fc,xc,yc,ee,ansx11,ansx12,ansx21,ansx22,ansy11,ansy12,ansy21,ansy22:longint;
    a,b,sum,hash,qq:array[0..2010,0..2010] of longint;
    ch:char;
    vi,vj:array[0..4] of longint;
    x,y:array[0..2000000] of longint;
    ok1x,ok1y,ok2x,ok2y:array[0..100000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

function ok:boolean;
  var i,j,c,c1,all,ee,o1,o2,i1,j1,flag,tot,ss:longint;
    procedure doithang(x,u,v:longint);
      var i:longint;
      begin
        if flag=0 then exit;
        for i:=u to v do
          begin
            if b[x,i]=0 then
              begin
                flag:=0;
                exit;
              end;
            if hash[x,i]<>tot then
              begin
                inc(ss);
                hash[x,i]:=tot;
              end;
          end;
      end;
    procedure doitlie(x,u,v:longint);
      var i:longint;
      begin
        if flag=0 then exit;
        for i:=u to v do
          begin
            if b[i,x]=0 then
              begin
                flag:=0;
                exit;
              end;
            if hash[i,x]<>tot then
              begin
                inc(ss);
                hash[i,x]:=tot;
              end;
          end;
      end;
  begin
    fillchar(sum,sizeof(sum),0);
    for i:=1 to m do
      for j:=1 to n do
        sum[i,j]:=sum[i,j-1]+b[i,j];
    o1:=0;o2:=0;
    for i:=1 to m-2 do
      for j:=1 to n-2 do
        if (b[i,j]=1) and (b[i,j+1]=1) and (b[i,j+2]=1) and (b[i+1,j]=1) and (b[i+2,j]=1) then
          begin
            if (i>2) and (sum[i-1,j+2]-sum[i-1,j-1]+sum[i-2,j+2]-sum[i-2,j-1]=6) then continue;
            if (j>2) and (sum[i,j-1]-sum[i,j-3]+sum[i+1,j-1]-sum[i+1,j-3]+sum[i+2,j-1]-sum[i+2,j-3]=6) then continue;
            inc(o1);
            ok1x[o1]:=i;
            ok1y[o1]:=j;
          end;
    for i:=3 to m do
      for j:=3 to n do
        if (b[i,j]=1) and (b[i,j-1]=1) and (b[i,j-2]=1) and (b[i-1,j]=1) and (b[i-2,j]=1) then
          begin
            if (i<m-1) and (sum[i+1,j]-sum[i+1,j-3]+sum[i+2,j]-sum[i+2,j-3]=6) then continue;
            if (j<n-1) and (sum[i,j+2]-sum[i,j]+sum[i-1,j+2]-sum[i-1,j]+sum[i-2,j+2]-sum[i-2,j]=6) then continue;
            inc(o2);
            ok2x[o2]:=i;
            ok2y[o2]:=j;
          end;
    //writeln(o1,' ',o2);
    if (o1<=10) and (o2<=10) then
      begin
        all:=0;
        for i:=1 to m do
          for j:=1 to n do
            all:=all+b[i,j];
        tot:=0;
        fillchar(hash,sizeof(hash),0);
        for i:=1 to o1 do
          for j:=1 to o2 do
            for i1:=1 to o1 do
              for j1:=1 to o2 do
                begin
                  inc(tot);
                  ss:=0;
                  flag:=1;
                  doithang(ok1x[i],ok1y[i],ok2y[j]);
                  doithang(ok2x[j],ok1y[i],ok2y[j]);
                  doitlie(ok1y[i],ok1x[i],ok2x[j]);
                  doitlie(ok2y[j],ok1x[i],ok2x[j]);
                  doithang(ok1x[i1],ok1y[i1],ok2y[j1]);
                  doithang(ok2x[j1],ok1y[i1],ok2y[j1]);
                  doitlie(ok1y[i1],ok1x[i1],ok2x[j1]);
                  doitlie(ok2y[j1],ok1x[i1],ok2x[j1]);
                  if (flag=1) and (ss=all) then
                    begin
                      writeln('YES');
                      if swapflag=1 then
                        begin
                          swap(ok1x[i],ok1y[i]);
                          swap(ok2x[j],ok2y[j]);
                          swap(ok1x[i1],ok1y[i1]);
                          swap(ok2x[j1],ok2y[j1]);
                        end;
                      writeln(ok1x[i],' ',ok1y[i],' ',ok2x[j],' ',ok2y[j]);
                      writeln(ok1x[i1],' ',ok1y[i1],' ',ok2x[j1],' ',ok2y[j1]);
                      exit(true);
                    end;
                end;
      end;
    for i:=1 to m do
      begin
        c:=1;
        while (c<=n) and (b[i,c]=0) do inc(c);
        if c>n then continue;
        ansx11:=i;ansy11:=c;
        c1:=c;
        while (c<=n) and (b[i,c]=1) do inc(c);
        dec(c);
        if (c-c1+1>=4) and (sum[i+1,c]-sum[i+1,c1-1]=c-c1+1) then
          if sum[i+2,c]-sum[i+2,c1-1]=c-c1+1 then
            begin
              ansx12:=i+2;ansy12:=c;
              qq:=b;
              for j:=c1 to c do b[i,j]:=0;
              for j:=c1+1 to c-1 do b[i+2,j]:=0;
              ee:=0;
              for i1:=1 to m do
                begin
                  for j1:=1 to n do
                    if b[i1,j1]=1 then
                      begin
                        inc(ee);
                        ansx21:=i1;ansy21:=j1;
                        if ee=2 then break;
                        xc:=i1;
                        yc:=j1;
                        repeat
                          b[xc,yc]:=0;
                          inc(xc);
                        until b[xc,yc]=0;
                        dec(xc);
                        repeat
                          b[xc,yc]:=0;
                          inc(yc);
                        until b[xc,yc]=0;
                        dec(yc);
                        ansx22:=xc;ansy22:=yc;
                        repeat
                          b[xc,yc]:=0;
                          dec(xc);
                        until b[xc,yc]=0;
                        inc(xc);
                        repeat
                          b[xc,yc]:=0;
                          dec(yc);
                        until b[xc,yc]=0;
                      end;
                  if ee=2 then break;
                end;
              if ee=1 then
                begin
                  if swapflag=1 then
                    begin
                      swap(ansx11,ansy11);
                      swap(ansx12,ansy12);
                      swap(ansx21,ansy21);
                      swap(ansx22,ansy22);
                    end;
                  writeln('YES');
                  writeln(ansx11,' ',ansy11,' ',ansx12,' ',ansy12);
                  writeln(ansx21,' ',ansy21,' ',ansx22,' ',ansy22);
                  exit(true);
                end;
              b:=qq;
              for j:=c1 to c do b[i+2,j]:=0;
              for j:=c1+1 to c-1 do b[i,j]:=0;
              ee:=0;
              for i1:=1 to m do
                begin
                  for j1:=1 to n do
                    if b[i1,j1]=1 then
                      begin
                        inc(ee);
                        ansx21:=i1;ansy21:=j1;
                        if ee=2 then break;
                        xc:=i1;
                        yc:=j1;
                        repeat
                          b[xc,yc]:=0;
                          inc(xc);
                        until b[xc,yc]=0;
                        dec(xc);
                        repeat
                          b[xc,yc]:=0;
                          inc(yc);
                        until b[xc,yc]=0;
                        dec(yc);
                        ansx22:=xc;ansy22:=yc;
                        repeat
                          b[xc,yc]:=0;
                          dec(xc);
                        until b[xc,yc]=0;
                        inc(xc);
                        repeat
                          b[xc,yc]:=0;
                          dec(yc);
                        until b[xc,yc]=0;
                      end;
                  if ee=2 then break;
                end;
              if ee=1 then
                begin
                  if swapflag=1 then
                    begin
                      swap(ansx11,ansy11);
                      swap(ansx12,ansy12);
                      swap(ansx21,ansy21);
                      swap(ansx22,ansy22);
                    end;
                  writeln('YES');
                  writeln(ansx11,' ',ansy11,' ',ansx12,' ',ansy12);
                  writeln(ansx21,' ',ansy21,' ',ansx22,' ',ansy22);
                  exit(true);
                end;
            end;
      end;
    exit(false);
  end;

begin
  readln(m,n);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(ch);
          if ch='#' then a[i,j]:=1 else a[i,j]:=0;
        end;
      readln;
    end;
  b:=a;
  tot:=0;
  vi[1]:=-1;vj[1]:=0;
  vi[2]:=0;vj[2]:=-1;
  vi[3]:=0;vj[3]:=1;
  vi[4]:=1;vj[4]:=0;
  for i:=1 to m do
    for j:=1 to n do
      if b[i,j]=1 then
        begin
          inc(tot);
          b[i,j]:=0;
          rc:=1;
          fc:=1;
          x[rc]:=i;
          y[rc]:=j;
          while rc<=fc do
            begin
              for ic:=1 to 4 do
                begin
                  xc:=x[rc]+vi[ic];
                  yc:=y[rc]+vj[ic];
                  if (xc>=1) and (xc<=m) and (yc>=1) and (yc<=n) and (b[xc,yc]=1) then
                    begin
                      b[xc,yc]:=0;
                      inc(fc);
                      x[fc]:=xc;
                      y[fc]:=yc;
                    end;
                end;
              inc(rc);
            end;
        end;
  if tot>2 then writeln('NO') else
    if tot=2 then
      begin
        b:=a;
        ee:=0;
        for i:=1 to m do
          begin
            for j:=1 to n do
              if b[i,j]=1 then
                begin
                  inc(ee);
                  if ee=1 then
                    begin
                      ansx11:=i;ansy11:=j;
                    end
                  else
                    begin
                      ansx21:=i;ansy21:=j;
                    end;
                  if ee=3 then break;
                  xc:=i;
                  yc:=j;
                  repeat
                    b[xc,yc]:=0;
                    inc(xc);
                  until b[xc,yc]=0;
                  dec(xc);
                  repeat
                    b[xc,yc]:=0;
                    inc(yc);
                  until b[xc,yc]=0;
                  dec(yc);
                  if ee=1 then
                    begin
                      ansx12:=xc;ansy12:=yc;
                    end
                  else
                    begin
                      ansx22:=xc;ansy22:=yc;
                    end;
                  repeat
                    b[xc,yc]:=0;
                    dec(xc);
                  until b[xc,yc]=0;
                  inc(xc);
                  repeat
                    b[xc,yc]:=0;
                    dec(yc);
                  until b[xc,yc]=0;
                end;
            if ee=3 then break;
          end;
        if ee=3 then writeln('NO') else
          begin
            writeln('YES');
            writeln(ansx11,' ',ansy11,' ',ansx12,' ',ansy12);
            writeln(ansx21,' ',ansy21,' ',ansx22,' ',ansy22);
          end;
      end
    else
      begin
        b:=a;
        swapflag:=0;
        if not ok then
          begin
            fillchar(b,sizeof(b),0);
            for i:=1 to m do
              for j:=1 to n do
                b[i,j]:=a[j,i];
            swapflag:=1;
            swap(m,n);
            if not ok then writeln('NO');
          end;
      end;
end.