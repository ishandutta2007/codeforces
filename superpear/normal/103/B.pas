type ljb=^pear;
     pear=record
            dest,biao:longint;
            next:ljb;
          end;

var head,tail:array[0..1000] of ljb;
    p:ljb;
    m,n,i,c,tot,x1,y1,rc,fc:longint;
    vis,u:array[0..1000] of longint;

procedure push(x,y,z:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.next:=nil;
    p^.biao:=z;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure search(s,t,last:longint);
  var p:ljb;
      c:longint;
  begin
    vis[s]:=t;
    p:=head[s]^.next;
    while p<>nil do
      begin
        if p^.biao<>last then
          begin
            c:=p^.dest;
            if vis[c]<>0 then
              begin
                if t-vis[c]>=2 then
                  writeln('FHTAGN!')
                else
                  writeln('NO');
                halt;
              end;
            search(c,t+1,p^.biao);
          end;
        p:=p^.next;
      end;
  end;

begin
  readln(n,m);
  if n<>m then
    begin
      writeln('NO');
      halt;
    end;
  for i:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  tot:=0;
  for i:=1 to m do
    begin
      readln(x1,y1);
      inc(tot);
      push(x1,y1,tot);
      push(y1,x1,tot);
    end;
  rc:=1;
  fc:=1;
  u[rc]:=1;
  fillchar(vis,sizeof(vis),0);
  vis[1]:=1;
  while rc<=fc do
    begin
      p:=head[u[rc]]^.next;
      while p<>nil do
        begin
          c:=p^.dest;
          if vis[c]=0 then
            begin
              vis[c]:=1;
              inc(fc);
              u[fc]:=c;
            end;
          p:=p^.next;
        end;
      inc(rc);
    end;
  if fc<>n then
    begin
      writeln('NO');
      halt;
    end;
  fillchar(vis,sizeof(vis),0);
  search(1,1,0);
end.