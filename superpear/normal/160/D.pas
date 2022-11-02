type ljb=^pear;
     pear=record
            dest,cost,where,spi:longint;
            next:ljb;
          end;

var head,tail:array[0..200000] of ljb;
    x,y,z,w,fa,dfn,low,ok,father,hash:array[0..200000] of longint;
    m,n,i,j,e,x1,y1,tot,all,now,qiu:longint;
    p:ljb;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,c:longint;
  begin
    i:=l;
    j:=r;
    c:=z[l+random(r-l+1)];
    repeat
      while z[i]<c do inc(i);
      while c<z[j] do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          swap(z[i],z[j]);
          swap(w[i],w[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function find(s:longint):longint;
  var e,u,k:longint;
  begin
    e:=s;
    while fa[e]<>e do e:=fa[e];
    u:=s;
    while fa[u]<>e do
      begin
        k:=fa[u];
        fa[u]:=e;
        u:=k;
      end;
  end;

procedure push(x,y,z,w:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.where:=w;
    p^.cost:=z;
    p^.next:=nil;
    p^.spi:=qiu;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure dfs(s:longint);
  var p:ljb;
      c:longint;
  begin
    hash[s]:=all;
    inc(tot);
    dfn[s]:=tot;
    low[s]:=tot;
    p:=head[s]^.next;
    while p<>nil do
      begin
        if p^.cost<>now then
          begin
            p:=p^.next;
            continue;
          end;
        c:=p^.dest;
        if hash[c]<>all then
          begin
            father[c]:=p^.spi;
            dfs(c);
            if low[c]>dfn[s] then
              ok[p^.where]:=2;
            if low[c]<low[s] then low[s]:=low[c];
          end
        else
          if father[s]<>p^.spi then
            if dfn[c]<low[s] then low[s]:=dfn[c];
        p:=p^.next;
      end;
  end;

begin
  randomize;

  readln(n,m);
  for i:=1 to m do
    begin
      readln(x[i],y[i],z[i]);
      w[i]:=i;
    end;
  sort(1,m);
  for i:=1 to n do
    fa[i]:=i;
  fillchar(ok,sizeof(ok),0);
  z[0]:=-maxlongint;
  for i:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.where:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  fillchar(low,sizeof(low),0);
  fillchar(dfn,sizeof(dfn),0);
  fillchar(father,sizeof(father),0);
  fillchar(hash,sizeof(hash),0);
  all:=0;
  qiu:=0;
  for i:=1 to m do
    if z[i]<>z[i-1] then
      begin
        inc(all);
        e:=i;
        while z[e+1]=z[e] do inc(e);
        for j:=i to e do
          begin
            x1:=find(x[j]);
            y1:=find(y[j]);
            if x1<>y1 then
              begin
                ok[w[j]]:=1;
                inc(qiu);
                push(x1,y1,z[j],w[j]);
                push(y1,x1,z[j],w[j]);
              end;
          end;
        now:=z[j];
        for j:=i to e do
          begin
            x1:=find(x[j]);
            y1:=find(y[j]);
            if x1<>y1 then
              fa[x1]:=y1;
            if hash[x1]<>all then dfs(x1);
            if hash[y1]<>all then dfs(y1);
          end;
      end;
  for i:=1 to m do
    begin
      if ok[i]=0 then writeln('none');
      if ok[i]=1 then writeln('at least one');
      if ok[i]=2 then writeln('any');
    end;
end.