type ljb=^pear;
     pear=record
            dest,cost:longint;
            next:ljb;
          end;

var head,tail:array[0..1000000] of ljb;
    big,n,i,down,up,tot,x1,y1,z1,node,flag,esk,last,ans,left,right,mid,fc1,fc2,start,over:longint;
    p:ljb;
    visit,hash,use,size,u,ans1,ans2,v,qqc1,qqc2,yuan:array[0..1000000] of longint;

procedure push(x,y,z:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.cost:=z;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure dfs(s:longint);
    var left,right,mid,allsize,min,mink,c,e1,e2,ko:longint;
      q:ljb;
    procedure calc(s:longint);
      var p:ljb;
          c:longint;
      begin
        size[s]:=1;
        hash[s]:=tot;
        p:=head[s]^.next;
        while p<>nil do
          begin
            c:=p^.dest;
            if (visit[c]=0) and (hash[c]<>tot) then
              begin
                calc(c);
                inc(size[s],size[c]);
              end;
            p:=p^.next;
          end;
      end;
    procedure findw(s:longint);
      var max,sum,c:longint;
          p:ljb;
      begin
        hash[s]:=tot;
        max:=0;
        sum:=0;
        p:=head[s]^.next;
        while p<>nil do
          begin
            c:=p^.dest;
            if (visit[c]=0) and (hash[c]<>tot) then
              begin
                findw(c);
                if size[c]>max then max:=size[c];
                inc(sum,size[c]);
              end;
            p:=p^.next;
          end;
        if allsize-sum>max then max:=allsize-sum;
        if max<min then
          begin
            min:=max;
            mink:=s;
          end;
      end;
    function ok(root1,root2,nowans:longint):boolean;
      var qcf1,qcf2,rc,fc,e,i:longint;
        procedure louit(s,flag,depth,eans:longint);
          var p:ljb;
              c:longint;
          begin
            hash[s]:=tot;
            if flag=1 then
              begin
                if depth>qcf1 then qcf1:=depth;
                if use[depth]<>tot then
                  begin
                    use[depth]:=tot;
                    ans1[depth]:=eans;
                    qqc1[depth]:=s;
                  end
                else
                  if eans>ans1[depth] then
                    begin
                      ans1[depth]:=eans;
                      qqc1[depth]:=s;
                    end;
              end
            else
              begin
                if depth>qcf2 then qcf2:=depth;
                if use[depth]<>tot then
                  begin
                    use[depth]:=tot;
                    ans2[depth]:=eans;
                    qqc2[depth]:=s;
                  end
                else
                  if eans>ans2[depth] then
                    begin
                      ans2[depth]:=eans;
                      qqc2[depth]:=s;
                    end;
              end;
            p:=head[s]^.next;
            while p<>nil do
              begin
                c:=p^.dest;
                if (visit[c]=0) and (hash[c]<>tot) then
                  begin
                    if p^.cost>=nowans then
                      louit(c,flag,depth+1,eans+1)
                    else
                      louit(c,flag,depth+1,eans-1);
                  end;
                p:=p^.next;
              end;
          end;
      begin
        qcf1:=0;qcf2:=0;
        inc(tot);
        louit(root1,1,0,0);
        inc(tot);
        louit(root2,2,0,0);
        rc:=1;
        fc:=0;
        e:=qcf2;
        for i:=0 to qcf1 do
          begin
            while (e>=0) and (i+e>=down) do
              begin
                while (fc>=rc) and (ans2[e]>=v[fc]) do dec(fc);
                inc(fc);
                u[fc]:=e;
                v[fc]:=ans2[e];
                dec(e);
              end;
            while (rc<=fc) and (i+u[rc]>up) do inc(rc);
            if (rc<=fc) and (ans1[i]+v[rc]>=0) then
              begin
                fc1:=qqc1[i];
                fc2:=qqc2[u[rc]];
                exit(true);
              end;
          end;
        exit(false);
      end;
  begin
    inc(tot);
    calc(s);
    allsize:=size[s];
    if allsize<=down then exit;
    min:=maxlongint;
    mink:=0;
    inc(tot);
    findw(s);
    inc(tot);
    new(q);
    q^.dest:=0;
    q^.cost:=0;
    q^.next:=nil;
    inc(node);
    head[node]:=q;
    tail[node]:=q;
    yuan[node]:=mink;
    new(q);
    q^.dest:=0;
    q^.cost:=0;
    q^.next:=nil;
    inc(node);
    head[node]:=q;
    tail[node]:=q;
    yuan[node]:=mink;
    inc(tot);
    calc(mink);
    p:=head[mink]^.next;
    c:=0;
    e1:=0;e2:=0;
    while p<>nil do
      begin
        if visit[p^.dest]=0 then
          begin
            c:=c+size[p^.dest];
            if c<=allsize div 2 then
              begin
                push(node-1,p^.dest,p^.cost);
                push(p^.dest,node-1,p^.cost);
                e1:=e1+size[p^.dest];
              end
            else
              begin
                push(node,p^.dest,p^.cost);
                push(p^.dest,node,p^.cost);
                e2:=e2+size[p^.dest];
              end;
          end;
        p:=p^.next;
      end;
    visit[mink]:=1;
    left:=ans;
    right:=big;
    repeat
      mid:=(left+right) div 2;
      if ok(node-1,node,mid) then
        begin
          if mid>ans then
            begin
              ans:=mid;
              start:=fc1;
              over:=fc2;
            end;
          left:=mid+1;
        end
      else
        right:=mid-1;
    until left>right;

    if allsize<=2 then exit;
    ko:=node;
    dfs(node-1);
    dfs(ko);
  end;

begin
  readln(n,down,up);
  for i:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.cost:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  big:=0;
  for i:=1 to n-1 do
    begin
      readln(x1,y1,z1);
      push(x1,y1,z1);
      push(y1,x1,z1);
      if z1>big then big:=z1;
    end;
  ans:=-1;
  tot:=0;
  fillchar(hash,sizeof(hash),0);
  fillchar(visit,sizeof(visit),0);
  fillchar(use,sizeof(use),0);
  for i:=0 to n do
    begin
      ans1[i]:=0;
      ans2[i]:=0;
    end;
  node:=n;
  for i:=1 to n do yuan[i]:=i;
  dfs(1);
  writeln(yuan[start],' ',yuan[over]);
end.