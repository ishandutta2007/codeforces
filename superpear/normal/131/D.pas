type ljb=^pear;
     pear=record
            dest:longint;
            next:ljb;
          end;

var n,i,x1,y1,rc,fc,c:longint;
    p:ljb;
    head,tail:array[0..10000] of ljb;
    back,huan,hash,u:array[0..10000] of longint;
    dis:array[0..3000,0..3000] of longint;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure search(s,fa:longint);
  var p:ljb;
      c,q,i,j,min:longint;
  begin
    p:=head[s]^.next;
    back[s]:=fa;
    hash[s]:=1;
    while p<>nil do
      begin
        c:=p^.dest;
        if c<>fa then
          begin
            if hash[c]=0 then search(c,s) else
              begin
                q:=s;
                repeat
                  huan[q]:=1;
                  q:=back[q];
                until q=c;
                huan[c]:=1;
                for i:=1 to n do
                  begin
                    if i>1 then write(' ');
                    min:=maxlongint;
                    for j:=1 to n do
                      if (huan[j]=1) and (dis[i,j]<min) then min:=dis[i,j];
                    write(min);
                  end;
                writeln;
                halt;
              end;
          end;
        p:=p^.next;
      end;
    hash[s]:=0;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  for i:=1 to n do
    begin
      readln(x1,y1);
      push(x1,y1);
      push(y1,x1);
    end;
  fillchar(dis,sizeof(dis),255);
  for i:=1 to n do
    begin
      rc:=1;
      fc:=1;
      u[rc]:=i;
      dis[i,i]:=0;
      while rc<=fc do
        begin
          p:=head[u[rc]]^.next;
          while p<>nil do
            begin
              c:=p^.dest;
              if dis[i,c]=-1 then
                begin
                  dis[i,c]:=dis[i,u[rc]]+1;
                  inc(fc);
                  u[fc]:=c;
                end;
              p:=p^.next;
            end;
          inc(rc);
        end;
    end;
  fillchar(back,sizeof(back),0);
  fillchar(hash,sizeof(hash),0);
  fillchar(huan,sizeof(huan),0);
  search(1,0);
end.