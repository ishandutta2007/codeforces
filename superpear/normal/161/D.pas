const maxn=3000000;

type ljb=^pear;
     pear=record
            dest:longint;
            next:ljb;
          end;

var ans:int64;
    head,tail:array[0..maxn] of ljb;
    f1,f2:array[0..60000] of longint;
    n,k,x1,y1,tot,node,i:longint;
    p:ljb;
    size,hash,vis:array[0..maxn] of longint;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure search(s:longint);
  var min,mink,nowsize,pq,oo,e,i:longint;
      p:ljb;

    procedure calc(s:longint);
      var p:ljb;
          c:longint;
      begin
        size[s]:=1;
        p:=head[s]^.next;
        vis[s]:=tot;
        while p<>nil do
          begin
            c:=p^.dest;
            if (hash[c]=0) and (vis[c]<>tot) then
              begin
                calc(c);
                inc(size[s],size[c]);
              end;
            p:=p^.next;
          end;
      end;
    procedure finds(s:longint);
      var e,q,c:longint;
          p:ljb;
      begin
        e:=0;
        q:=0;
        p:=head[s]^.next;
        vis[s]:=tot;
        while p<>nil do
          begin
            c:=p^.dest;
            if (hash[c]=0) and (vis[c]<>tot) then
              begin
                finds(c);
                if size[c]>e then e:=size[c];
                q:=q+size[c];
              end;
            p:=p^.next;
          end;
        if nowsize-q>e then e:=nowsize-q;
        if e<min then
          begin
            min:=e;
            mink:=s;
          end;
      end;
    procedure dfs(s,now,flag:longint);
      var p:ljb;
          c:longint;
      begin
        if flag=1 then inc(f1[now]) else inc(f2[now]);
        vis[s]:=tot;
        p:=head[s]^.next;
        while p<>nil do
          begin
            c:=p^.dest;
            if (hash[c]=0) and (vis[c]<>tot) then
              dfs(c,now+1,flag);
            p:=p^.next;
          end;
      end;
  begin
    inc(tot);
    calc(s);
    min:=maxlongint;
    mink:=0;
    nowsize:=size[s];
    if nowsize<=k then exit;
    inc(tot);
    finds(s);

    inc(node,2);

    inc(tot);
    calc(mink);
    oo:=nowsize-1;
    p:=head[mink]^.next;
    pq:=0;
    while p<>nil do
      begin
        e:=p^.dest;
        if pq+size[e]<=oo div 2 then
          begin
            push(node-1,p^.dest);
            push(p^.dest,node-1);
            pq:=pq+size[e];
          end
        else
          begin
            push(node,p^.dest);
            push(p^.dest,node);
          end;
        p:=p^.next;
      end;

    hash[mink]:=1;
    fillchar(f1,sizeof(f1),0);
    fillchar(f2,sizeof(f2),0);
    inc(tot);
    dfs(node-1,0,1);
    inc(tot);
    dfs(node,0,2);

    for i:=1 to k-1 do
      ans:=ans+int64(f1[i])*f2[k-i];

    if nowsize<=2 then exit;
    oo:=node;
    search(oo-1);
    search(oo);
  end;

begin         {
  assign(input,'D.in');
  assign(output,'D.out');
  reset(input);
  rewrite(output);
               }
  readln(n,k);
  for i:=1 to maxn do
    begin
      new(p);
      p^.dest:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  for i:=1 to n-1 do
    begin
      readln(x1,y1);
      push(x1,y1);
      push(y1,x1);
    end;
  if k=1 then
    begin
      writeln(n-1);
      close(input);
      close(output);
      halt;
    end;
  fillchar(hash,sizeof(hash),0);
  fillchar(vis,sizeof(vis),0);
  node:=n;
  ans:=0;
  search(1);
  writeln(ans);

  close(input);
  close(output);
end.