const maxn=1000000;
type ljb=^pear;
     pear=record
            dest:longint;
            next:ljb;
          end;

var a,s:array[0..1100000] of string[11];
    st:ansistring;
    o,i,j,tt,lst,lsc,left,right,mid,top,now,v,m,ans,ff:longint;
    p:ljb;
    head,tail:array[0..1000000] of ljb;
    sc:string;
    flag,c,num,m1,stack:array[0..1000000] of longint;
    u:array[0..1000] of longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure swaps(var a,b:string);
  var r:string[11];
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j:longint;
      x:string[11];
  begin
    i:=l;
    j:=r;
    x:=a[l+random(r-l+1)];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if i<=j then
        begin
          swaps(a[i],a[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure search(s,e:longint);
  var p:ljb;
  begin
    if u[v]=c[s] then
      if e>=v-1 then inc(ans);
    p:=head[s]^.next;
    if u[e+1]=c[s] then inc(e);
    while p<>nil do
      begin
        search(p^.dest,e);
        p:=p^.next;
      end;
  end;

begin
  randomize;

  readln(st);
  lst:=length(st);
  o:=0;
  tt:=1;
  for i:=1 to lst do
    if st[i]='<' then
      sc:=''
    else
      if st[i]='>' then
        begin
          inc(o);
          lsc:=length(sc);
          if sc[lsc]='/' then
            begin
              flag[o]:=2;
              delete(sc,lsc,1);
            end
          else
            if sc[1]='/' then
              begin
                flag[o]:=1;
                delete(sc,1,1);
              end
            else
              flag[o]:=0;
          s[o]:=sc;
          if flag[o]<>1 then
            begin
              inc(tt);
              num[o]:=tt;
            end;
        end
      else
        sc:=sc+st[i];
  a:=s;
  sort(1,o);
  m1[0]:=0;
  a[0]:='Orz Csx&Cxy';
  for i:=1 to o do
    if a[i]<>a[i-1] then m1[i]:=m1[i-1]+1 else m1[i]:=m1[i-1];
  for i:=1 to o do
    begin
      left:=1;
      right:=o;
      repeat
        mid:=(left+right) div 2;
        if s[i]=a[mid] then break;
        if s[i]>a[mid] then left:=mid+1 else right:=mid-1;
      until left>right;
      c[num[i]]:=m1[mid];
    end;
  for i:=1 to maxn do
    begin
      new(p);
      p^.dest:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  fillchar(stack,sizeof(stack),0);
  top:=1;
  stack[1]:=1;
  now:=1;
  for i:=1 to o do
    if flag[i]=2 then push(now,num[i]) else
      if flag[i]=0 then
        begin
          push(now,num[i]);
          inc(top);
          stack[top]:=num[i];
          now:=num[i];
        end
      else
        begin
          dec(top);
          now:=stack[top];
        end;
  //for i:=1 to o do writeln(num[i],' ',c[num[i]]);
  readln(m);
  for i:=1 to m do
    begin
      readln(st);
      st:=st+' ';
      sc:='';
      v:=0;
      lst:=length(st);
      ff:=1;
      for j:=1 to lst do
        if st[j]=' ' then
          begin
            inc(v);
            left:=1;
            right:=o;
            repeat
              mid:=(left+right) div 2;
              if sc=a[mid] then break;
              if sc>a[mid] then left:=mid+1 else right:=mid-1;
            until left>right;
            if sc<>a[mid] then
              begin
                ff:=0;
                break;
              end;
            u[v]:=m1[mid];
            sc:='';
          end
        else
          sc:=sc+st[j];
      ans:=0;
      if ff=1 then search(1,0);
      writeln(ans);
    end;
end.