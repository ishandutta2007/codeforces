type ljb=^pear;
     pear=record
            dest,num:longint;
            next:ljb;
          end;

var head,tail:array[0..2000] of ljb;
    fa,bian,now:array[0..2000] of longint;
    x,y,z,use:array[0..200000] of longint;
    m,n,o1,o2,o,q,i,k,x1,y1,sec,sed,e,flag:longint;
    ch:char;
    p,qc:ljb;
    hash:array[0..100000] of integer;

procedure push(x,y,z:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.num:=z;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure search(s:longint);
  var p:ljb;
      c:longint;
  begin
    p:=head[s]^.next;
    while p<>nil do
      begin
        c:=p^.dest;
        if (hash[p^.num]=0) and (bian[c]=0) then
          begin
            bian[c]:=p^.num;
            search(c);
          end;
        p:=p^.next;
      end;
  end;

begin
  readln(n,m);
  if n mod 2=0 then
    begin
      writeln(-1);
      halt;
    end;
  o1:=0;
  o2:=m+1;
  for i:=1 to m do
    begin
      readln(x1,y1,ch,ch);
      if ch='S' then
        begin
          inc(o1);
          x[o1]:=x1;y[o1]:=y1;z[o1]:=i;
        end
      else
        begin
          dec(o2);
          x[o2]:=x1;y[o2]:=y1;z[o2]:=i;
        end;
    end;
  for i:=1 to n do
    fa[i]:=i;
  if (o1<(n-1) div 2) or (m-o1<(n-1) div 2) then
    begin
      writeln(-1);
      halt;
    end;
  o:=0;
  sec:=0;
  for i:=1 to o1 do
    begin
      x1:=x[i];y1:=y[i];
      while fa[x1]<>x1 do x1:=fa[x1];
      while fa[y1]<>y1 do y1:=fa[y1];
      if x1<>y1 then
        begin
          fa[x1]:=y1;
          inc(sec);
          use[i]:=1;
          inc(o);
          now[o]:=i;
        end;
    end;
  if sec<(n-1) div 2 then
    begin
      writeln(-1);
      halt;
    end;
  sed:=0;
  for i:=o1+1 to m do
    begin
      x1:=x[i];y1:=y[i];
      while fa[x1]<>x1 do x1:=fa[x1];
      while fa[y1]<>y1 do y1:=fa[y1];
      if x1<>y1 then
        begin
          fa[x1]:=y1;
          inc(sed);
          use[i]:=1;
          inc(o);
          now[o]:=i;
        end;
    end;
  if sec+sed<>n-1 then
    begin
      writeln(-1);
      halt;
    end;
  i:=o1+1;
  q:=sec-(n-1) div 2;
  for k:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.num:=0;
      p^.next:=nil;
      head[k]:=p;
      tail[k]:=p;
    end;
  for k:=1 to o do
    begin
      push(x[now[k]],y[now[k]],now[k]);
      push(y[now[k]],x[now[k]],now[k]);
    end;
  fillchar(hash,sizeof(hash),0);
  while q>0 do
    begin
      while (i<=m) and (use[i]=1) do inc(i);
      if i>m then break;
      fillchar(bian,sizeof(bian),0);
      bian[x[i]]:=-1;
      search(x[i]);
      e:=y[i];
      flag:=1;
      while e<>x[i] do
        begin
          if bian[e]<=o1 then
            begin
              use[i]:=1;
              use[bian[e]]:=0;
              for k:=1 to o do
                if now[k]=bian[e] then
                  begin
                    hash[bian[e]]:=1;
                    now[k]:=i;
                    push(x[i],y[i],i);
                    push(y[i],x[i],i);
                    break;
                  end;
              flag:=0;
              break;
            end;
          if x[bian[e]]=e then e:=y[bian[e]] else e:=x[bian[e]];
        end;
      if flag=0 then dec(q);
      inc(i);
    end;
  if q>0 then writeln(-1) else
    begin
      writeln(n-1);
      for i:=1 to n-2 do write(z[now[i]],' ');
      if n>1 then writeln(z[now[n-1]]) else writeln;
    end;
end.