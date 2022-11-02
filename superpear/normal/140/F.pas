var x,y:array[0..200000] of longint;
    xc,yc,ansx,ansy:array[0..200] of longint;
    n,k,i,j,ans,flag,e,o:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,c,d,e:longint;
  begin
    i:=l;
    j:=r;
    e:=l+random(r-l+1);
    c:=x[e];
    d:=y[e];
    repeat
      while (x[i]<c) or ((x[i]=c) and (y[i]<d)) do inc(i);
      while (c<x[j]) or ((c=x[j]) and (d<y[j])) do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function check(x1,y1:longint):boolean;
  var u,v,o,xc,yc:longint;
  begin
    u:=1;
    v:=n;
    o:=k;
    while u<=v do
      begin
        xc:=x1-x[u];
        yc:=y1-y[u];
        while (u<v) and ((x[v]>xc) or ((x[v]=xc) and (y[v]>yc))) do
          begin
            dec(v);
            dec(o);
            if o<0 then exit(false);
          end;
        if (x[v]<>xc) or (y[v]<>yc) then
          begin
            dec(o);
            if o<0 then exit(false);
          end
        else
          dec(v);
        inc(u);
      end;
    exit(true);
  end;

begin
  randomize;

  readln(n,k);
  for i:=1 to n do
    readln(x[i],y[i]);
  if k>=n then
    begin
      writeln(-1);
      halt;
    end;
  sort(1,n);

  e:=(n+1) div 2;
  o:=0;
  for i:=e-6 to e+6 do
    for j:=i to e+6 do
      if (i>0) and (i<=n) and (j>0) and (j<=n) then
        begin
          inc(o);
          xc[o]:=(x[i]+x[j]);
          yc[o]:=(y[i]+y[j]);
        end;
  ans:=0;
  for i:=1 to o do
    begin
      flag:=1;
      for j:=1 to i-1 do
        if (xc[i]=xc[j]) and (yc[i]=yc[j]) then
          begin
            flag:=0;
            break;
          end;
      if flag=1 then
        if check(xc[i],yc[i]) then
          begin
            inc(ans);
            ansx[ans]:=xc[i];
            ansy[ans]:=yc[i];
          end;
    end;
  writeln(ans);
  for i:=1 to ans do
    writeln(ansx[i]/2:0:10,' ',ansy[i]/2:0:10);
end.