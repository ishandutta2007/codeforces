type ljb=^pear;
     pear=record
            dest,flow,cost:longint;
            next,other:ljb;
          end;

var head,tail,pre:array[0..1000] of ljb;
    m,n,i,j,s,ans,rc,fc,uu,o,k,e:longint;
    data,num,cost,flow,va:array[0..1000] of longint;
    u:array[0..1000000] of longint;
    p:ljb;
    stc:array[0..1000] of string;
    stt:string;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

function low(s:longint):longint;
  begin
    exit(s and (-s));
  end;

function getc(s:longint):longint;
  var e:longint;
  begin
    e:=0;
    while s>0 do
      begin
        inc(e);
        s:=s-low(s);
      end;
    exit(e);
  end;

procedure push(x,y,z:longint);
  var p,q:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.flow:=1;
    p^.cost:=z;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
    new(q);
    q^.dest:=x;
    q^.flow:=0;
    q^.cost:=-z;
    q^.next:=nil;
    tail[y]^.next:=q;
    tail[y]:=q;
    p^.other:=q;
    q^.other:=p;
  end;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      read(data[i]);
      num[i]:=getc(data[i]);
    end;
  s:=n*2+m+1;
  for i:=0 to s do
    begin
      new(p);
      p^.dest:=0;
      p^.flow:=0;
      p^.cost:=0;
      p^.other:=nil;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  for i:=1 to n+m do
    push(0,i,0);
  for i:=n+m+1 to s-1 do
    push(i,s,0);
  for i:=1 to n do
    for j:=i+1 to n do
      if data[i]=data[j] then push(i,j+n+m,0)
                         else push(i,j+n+m,num[j]);
  for i:=n+1 to n+m do
    for j:=1 to n do
      push(i,j+n+m,num[j]);
  ans:=0;
  repeat
    fillchar(flow,sizeof(flow),0);
    filldword(cost,sizeof(cost) div 4,maxlongint);
    rc:=1;
    fc:=1;
    u[rc]:=0;
    cost[0]:=0;
    flow[0]:=maxlongint;
    while rc<=fc do
      begin
        p:=head[u[rc]]^.next;
        while p<>nil do
          begin
            if (p^.flow>0) and (cost[u[rc]]+p^.cost<cost[p^.dest]) then
              begin
                cost[p^.dest]:=cost[u[rc]]+p^.cost;
                flow[p^.dest]:=min(flow[u[rc]],p^.flow);
                pre[p^.dest]:=p;
                inc(fc);
                u[fc]:=p^.dest;
              end;
            p:=p^.next;
          end;
        inc(rc);
      end;
    if flow[s]=0 then break;
    ans:=ans+cost[s]*flow[s];
    uu:=s;
    while uu<>0 do
      begin
        dec(pre[uu]^.flow,flow[s]);
        inc(pre[uu]^.other^.flow,flow[s]);
        uu:=pre[uu]^.other^.dest;
      end;
  until false;
  o:=0;
  fillchar(va,sizeof(va),0);
  for i:=1 to n do
    begin
      k:=i+n+m;
      p:=head[k]^.next;
      while p<>nil do
        begin
          if p^.flow=1 then break;
          p:=p^.next;
        end;
      e:=p^.dest;
      if (e<=n) and (data[e]<>data[i]) then
        begin
          inc(o);
          str(data[i],stt);
          stc[o]:=chr(va[e]+96)+'='+stt;
          va[i]:=va[e];
        end
      else
        if (e<=n) and (data[e]=data[i]) then
          va[i]:=va[e]
        else
          begin
            inc(o);
            str(data[i],stt);
            stc[o]:=chr(e-n+96)+'='+stt;
            va[i]:=e-n;
          end;
      inc(o);
      stc[o]:='print('+chr(va[i]+96)+')';
    end;
  writeln(o,' ',ans);
  for i:=1 to o do writeln(stc[i]);
end.