const bigp=1997062002607991;

type ljb=^pear;
     pear=record
            num:longint;
            next:ljb;
          end;

var ans,e,s:int64;
    m,n,i,x1,y1,v,last:longint;
    head,tail:array[0..1000001] of ljb;
    a,f:array[0..1000001] of int64;
    p:ljb;
    x,y:array[0..1000001] of longint;

function cheng(x,y:int64):int64;
  var s:int64;
  begin
    s:=0;
    while y>0 do
      begin
        if y mod 2=1 then s:=(int64(s)+x) mod bigp;
        y:=y div 2;
        x:=(x*2) mod bigp;
      end;
    exit(s);
  end;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.num:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure sort(l,r:longint);
  var i,j:longint;
      x,y:int64;
  begin
    i:=l;
    j:=r;
    x:=a[l+random(r-l+1)];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if i<=j then
        begin
          y:=a[i];
          a[i]:=a[j];
          a[j]:=y;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  f[0]:=1;
  for i:=1 to 1000000 do f[i]:=f[i-1]*2 mod bigp;
  randomize;
  readln(n,m);
  for i:=1 to n do
    begin
      new(p);
      p^.num:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  for i:=1 to m do
    begin
      readln(x1,y1);
      x[i]:=x1;y[i]:=y1;
      push(x1,y1);
      push(y1,x1);
    end;
  for i:=1 to n do
    begin
      e:=1;
      s:=0;
      p:=head[i]^.next;
      while p<>nil do
        begin
          s:=(int64(s)+f[p^.num]) mod bigp;
          p:=p^.next;
        end;
      a[i]:=s;
    end;
  sort(1,n);
  ans:=0;
  last:=0;
  a[0]:=-maxlongint;
  a[n+1]:=-maxlongint;
  for i:=1 to n+1 do
    if a[i]<>a[i-1] then
      begin
        v:=i-last;
        ans:=ans+int64(v)*(v-1) div 2;
        last:=i;
      end;
  for i:=1 to n do push(i,i);
  for i:=1 to n do
    begin
      e:=1;
      s:=0;
      p:=head[i]^.next;
      while p<>nil do
        begin
          s:=(int64(s)+f[p^.num]) mod bigp;
          p:=p^.next;
        end;
      s:=(int64(s)+e) mod bigp;
      a[i]:=s;
    end;
  for i:=1 to m do
    if a[x[i]]=a[y[i]] then inc(ans);
  writeln(ans);
end.