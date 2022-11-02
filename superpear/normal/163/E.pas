{$m 1000000000}
type ljb=^gobble;
     autoac=^pear;
     gobble=record
              dest:longint;
              next:ljb;
            end;
     pear=record
            child:array['a'..'z'] of autoac;
            back,father:autoac;
            ch:char;
            ti:longint;
          end;

var root,p,q:autoac;
    u:array[0..2000000] of autoac;
    ic,ch:char;
    st:ansistring;
    m,n,i,j,rc,fc,o,ans,top,num,lst,tt:longint;
    f,left,right,hash,flag,qr:array[0..2000000] of longint;
    head,tail:array[0..2000000] of ljb;
    c,ne:ljb;

function low(s:longint):longint;
  begin
    exit(s and (-s));
  end;

procedure plus(s,num:longint);
  begin
    while s<=o do
      begin
        inc(f[s],num);
        s:=s+low(s);
      end;
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

procedure push(x,y:longint);
  var c:ljb;
  begin
    new(c);
    c^.dest:=y;
    c^.next:=nil;
    tail[x]^.next:=c;
    tail[x]:=c;
  end;

procedure search(s:longint);
  var p:ljb;
  begin
    inc(o);
    left[s]:=o;
    p:=head[s]^.next;
    while p<>nil do
      begin
        search(p^.dest);
        p:=p^.next;
      end;
    inc(o);
    right[s]:=o;
  end;

begin
  new(root);
  for ic:='a' to 'z' do
    root^.child[ic]:=nil;
  root^.back:=root;
  root^.father:=root;
  root^.ch:=' ';
  tt:=1;
  root^.ti:=1;
  fillchar(flag,sizeof(flag),0);
  readln(m,n);
  for i:=1 to n do
    begin
      readln(st);
      lst:=length(st);
      p:=root;
      for j:=1 to lst do
        begin
          if p^.child[st[j]]=nil then
            begin
              new(q);
              for ic:='a' to 'z' do
                q^.child[ic]:=nil;
              q^.back:=nil;
              q^.father:=p;
              q^.ch:=st[j];
              inc(tt);
              q^.ti:=tt;
              p^.child[st[j]]:=q;
              p:=q;
            end
          else
            p:=p^.child[st[j]];
        end;
      flag[p^.ti]:=i;
      qr[i]:=p^.ti;
    end;
  for i:=1 to tt do
    begin
      new(c);
      c^.dest:=0;
      c^.next:=nil;
      head[i]:=c;
      tail[i]:=c;
    end;
  rc:=1;
  fc:=1;
  u[rc]:=root;
  while rc<=fc do
    begin
      if u[rc]<>root then
        begin
          p:=u[rc]^.father^.back;
          ch:=u[rc]^.ch;
          while (p<>root) and (p^.child[ch]=nil) do p:=p^.back;
          if p^.child[ch]<>nil then p:=p^.child[ch];
          if p=u[rc] then u[rc]^.back:=p^.father else u[rc]^.back:=p;
          push(u[rc]^.back^.ti,u[rc]^.ti);
        end;
        for ic:='a' to 'z' do
          if u[rc]^.child[ic]<>nil then
            begin
              inc(fc);
              u[fc]:=u[rc]^.child[ic];
            end;
      inc(rc);
    end;
  o:=0;
  search(1);
  for i:=1 to tt do
    if flag[i]<>0 then
      begin
        plus(left[i],1);
        plus(right[i]+1,-1);
      end;
  fillchar(hash,sizeof(hash),0);
  for i:=1 to m do
    begin
      read(ch);
      if ch='?' then
        begin
          readln(st);
          lst:=length(st);
          ans:=0;
          p:=root;
          for j:=1 to lst do
            begin
              ch:=st[j];
              while (p<>root) and (p^.child[ch]=nil) do
                p:=p^.back;
              if p^.child[ch]<>nil then p:=p^.child[ch];
              //writeln(p^.ti,' ',flag[p^.ti]);
              inc(ans,getsum(left[p^.ti]));
            end;
          writeln(ans);
        end;
      if ch='-' then
        begin
          readln(num);
          num:=qr[num];
          if hash[num]=0 then
            begin
              plus(left[num],-1);
              plus(right[num]+1,1);
              hash[num]:=1;
            end;
        end;
      if ch='+' then
        begin
          readln(num);
          num:=qr[num];
          if hash[num]=1 then
            begin
              plus(left[num],1);
              plus(right[num]+1,-1);
              hash[num]:=0;
            end;
        end;
    end;
end.