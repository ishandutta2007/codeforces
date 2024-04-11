type link1=^pear;
     pear=record
            num,dest:longint;
            next:link1;
          end;

     link2=^gobble;
     gobble=record
            num,where:longint;
            next:link2;
          end;

var head,tail:array[0..210000] of link1;
    qhead,qtail:array[0..210000] of link2;
    hash,ans,askx,asky,father,f,fa,go1,go2:array[0..210000] of longint;
    m,n,x1,y1,i,cs,o:longint;
    p:link1;
    q:link2;

function low(s:longint):longint;
  begin
    exit(s and (-s));
  end;

function getsum(s:longint):longint;
  var e:longint;
  begin
    e:=0;
    while s>0 do
      begin
        e:=e+f[s];
        s:=s-low(s);
      end;
    exit(e);
  end;

procedure plus(s,c:longint);
  begin
    while s<=o do
      begin
        inc(f[s],c);
        s:=s+low(s);
      end;
  end;

procedure search(s:longint);
  var p:link1;
      q:link2;
      c,t,e:longint;
  begin
    hash[s]:=1;
    q:=qhead[s]^.next;
    while q<>nil do
      begin
        c:=q^.num;
        while father[c]<>c do
          c:=father[c];
        t:=q^.num;
        while father[t]<>t do
          begin
            e:=father[t];
            father[t]:=c;
            t:=e;
          end;
        if hash[c]=1 then
          ans[q^.where]:=c;
        q:=q^.next;
      end;
    p:=head[s]^.next;
    while p<>nil do
      begin
        c:=p^.dest;
        if hash[c]<>1 then
          begin
            search(c);
            father[c]:=s;
          end;
        p:=p^.next;
      end;
  end;

procedure dfs(s:longint);
  var p:link1;
      c:longint;
  begin
    hash[s]:=1;
    p:=head[s]^.next;
    while p<>nil do
      begin
        c:=p^.dest;
        if hash[c]=0 then
          begin
            inc(o);
            go1[p^.num]:=o;
            fa[c]:=o;
            dfs(c);
            inc(o);
            go2[p^.num]:=o;
          end;
        p:=p^.next;
      end;
  end;

procedure doit(x,y:longint);
  begin
    //writeln(x,' ',y,'   ',fa[x]+1,' ',fa[y]);
    plus(fa[x]+1,1);
    plus(fa[y]+1,-1);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
        new(p);
        p^.num:=0;
        p^.next:=nil;
        head[i]:=p;
        tail[i]:=p;
        new(q);
        q^.num:=0;
        q^.next:=nil;
        q^.where:=0;
        qhead[i]:=q;
        qtail[i]:=q;
    end;
  for i:=1 to n-1 do
    begin
      readln(x1,y1);
        new(p);
        p^.dest:=y1;
        p^.num:=i;
        p^.next:=nil;
        tail[x1]^.next:=p;
        tail[x1]:=p;
        new(p);
        p^.dest:=x1;
        p^.num:=i;
        p^.next:=nil;
        tail[y1]^.next:=p;
        tail[y1]:=p;
    end;
  readln(m);
  for i:=1 to m do
    begin
      readln(askx[i],asky[i]);
      ans[i]:=0;
        new(q);
        q^.num:=asky[i];
        q^.next:=nil;
        q^.where:=i;
        qtail[askx[i]]^.next:=q;
        qtail[askx[i]]:=q;
        new(q);
        q^.num:=askx[i];
        q^.next:=nil;
        q^.where:=i;
        qtail[asky[i]]^.next:=q;
        qtail[asky[i]]:=q;
    end;
  fillchar(hash,sizeof(hash),0);
  for i:=1 to n do father[i]:=i;
  search(1);
  fillchar(go1,sizeof(go1),0);
  fillchar(go2,sizeof(go2),0);
  fillchar(fa,sizeof(fa),0);
  fillchar(hash,sizeof(hash),0);
  o:=0;
  dfs(1);
  fillchar(f,sizeof(f),0);
  for i:=1 to m do
    begin
      cs:=ans[i];
      if cs<>askx[i] then doit(cs,askx[i]);
      if cs<>asky[i] then doit(cs,asky[i]);
    end;
  for i:=1 to n-1 do
    begin
      if i<>1 then write(' ');
      write(getsum(go1[i])-getsum(go2[i]));
    end;
  writeln;
end.