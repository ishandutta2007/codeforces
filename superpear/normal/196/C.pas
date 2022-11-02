type arr=array[0..1600] of longint;
     ljb=^pear;
     pear=record
            dest:longint;
            next:ljb;
          end;

var head,tail:array[0..1600] of ljb;
    p:ljb;
    n,i,x1,y1,up,right,maxk:longint;
    x,y,w,hash,size,ans:arr;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

procedure calc(s:longint);
  var p:ljb;
  begin
    hash[s]:=1;
    size[s]:=1;
    p:=head[s]^.next;
    while p<>nil do
      begin
        if hash[p^.dest]=0 then
          begin
            calc(p^.dest);
            inc(size[s],size[p^.dest]);
          end;
        p:=p^.next;
      end;
  end;

function chaji(x1,y1,x2,y2,x3,y3:longint):boolean;
  var s:int64;
  begin
    dec(x2,x1);dec(y2,y1);
    dec(x3,x1);dec(y3,y1);
    s:=int64(x2)*y3-int64(x3)*y2;
    if s>0 then exit(true) else exit(false);
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure doit(s:longint;x,y,w:arr);
  var x1,y1,w1:arr;
      p:ljb;
      now:longint;
    procedure sort(l,r:longint);
      var i,j,xc,yc,e:longint;
      begin
        i:=l;
        j:=r;
        e:=l+random(r-l+1);
        xc:=x[e];yc:=y[e];
        repeat
          while chaji(x[1],y[1],xc,yc,x[i],y[i]) do inc(i);
          while chaji(x[1],y[1],x[j],y[j],xc,yc) do dec(j);
          if i<=j then
            begin
              swap(x[i],x[j]);
              swap(y[i],y[j]);
              swap(w[i],w[j]);
              inc(i);
              dec(j);
            end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
     end;
  begin
    hash[s]:=1;
    ans[w[1]]:=s;
    sort(2,size[s]);
    fillchar(x1,sizeof(x1),0);
    fillchar(y1,sizeof(y1),0);
    fillchar(w1,sizeof(w1),0);
    p:=head[s]^.next;
    now:=2;
    while p<>nil do
      begin
        if hash[p^.dest]=0 then
          begin
            for i:=now to now+size[p^.dest]-1 do
              begin
                x1[i-now+1]:=x[i];
                y1[i-now+1]:=y[i];
                w1[i-now+1]:=w[i];
              end;
            now:=now+size[p^.dest];
            doit(p^.dest,x1,y1,w1);
          end;
        p:=p^.next;
      end;
  end;

begin
  randomize;
  readln(n);
  for i:=1 to n do
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
  fillchar(hash,sizeof(hash),0);
  calc(1);
  up:=-maxlongint;
  right:=-maxlongint;
  for i:=1 to n do
    begin
      readln(x[i],y[i]);
      w[i]:=i;
      if (y[i]>up) or ((y[i]=up) and (x[i]>right)) then
        begin
          up:=y[i];
          right:=x[i];
          maxk:=i;
        end;
    end;
  swap(x[1],x[maxk]);swap(y[1],y[maxk]);swap(w[1],w[maxk]);
  fillchar(ans,sizeof(ans),0);
  fillchar(hash,sizeof(hash),0);
  doit(1,x,y,w);
  for i:=1 to n-1 do write(ans[i],' ');writeln(ans[n]);
end.