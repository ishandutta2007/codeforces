type ljb=^pear;
     pear=record
            dest,leng:longint;
            next:ljb;
          end;

var p:ljb;
    head,tail:array[0..400000] of ljb;
    m,n,i,s,l,rc,fc,t,z1,ans:longint;
    x,y,z,f:array[0..400000] of longint;
    u:array[0..4000000] of longint;

procedure push(x,y,z:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.leng:=z;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

begin
  readln(n,m,s);
  for i:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.leng:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  for i:=1 to m do
    begin
      readln(x[i],y[i],z[i]);
      push(x[i],y[i],z[i]);
      push(y[i],x[i],z[i]);
    end;
  readln(l);
  rc:=1;
  fc:=1;
  u[rc]:=s;
  filldword(f,sizeof(f) div 4,maxlongint);
  f[s]:=0;
  while rc<=fc do
    begin
      p:=head[u[rc]]^.next;
      while p<>nil do
        begin
          if f[u[rc]]+p^.leng<f[p^.dest] then
            begin
              f[p^.dest]:=f[u[rc]]+p^.leng;
              inc(fc);
              u[fc]:=p^.dest;
            end;
          p:=p^.next;
        end;
      inc(rc);
    end;
  ans:=0;
  for i:=1 to n do
    if f[i]=l then
      inc(ans);
  for i:=1 to m do
    begin
      z1:=-1;
      if (f[x[i]]<l) and (f[x[i]]+z[i]>l) then
        begin
          t:=l-f[x[i]];
          if f[y[i]]+z[i]-t>=l then
            begin
              inc(ans);
              z1:=t;
            end;
        end;
      if (f[y[i]]<l) and (f[y[i]]+z[i]>l) then
        begin
          t:=l-f[y[i]];
          if f[x[i]]+z[i]-t>=l then
            if t+z1<>z[i] then
              inc(ans);
        end;
    end;
  writeln(ans);
end.