type ljb=^pear;
     pear=record
            dest:longint;
            next:ljb;
          end;

var head,tail:array[0..230000] of ljb;
    f,hash:array[0..230000] of longint;
    u:array[0..3000000] of longint;
    m,n,k,i,ch,x1,y1,start,over,left,right,mid:longint;
    p:ljb;

procedure push(x,y:longint);
  var p:ljb;
  begin
    new(p);
    p^.dest:=y;
    p^.next:=nil;
    tail[x]^.next:=p;
    tail[x]:=p;
  end;

function check(s:longint):boolean;
  var rc,fc,c,c1:longint;
      p:ljb;
  begin
    filldword(f,sizeof(f) div 4,maxlongint);
    rc:=1;
    fc:=1;
    u[rc]:=start;
    f[start]:=0;
    while rc<=fc do
      begin
        p:=head[u[rc]]^.next;
        while p<>nil do
          begin
            c:=p^.dest;
            if f[u[rc]]<s then
              begin
                if hash[c]=1 then c1:=0 else c1:=f[u[rc]]+1;
                if c1<f[c] then
                  begin
                    f[c]:=c1;
                    inc(fc);
                    u[fc]:=c;
                  end;
              end;
            p:=p^.next;
          end;
        inc(rc);
      end;
    if f[over]<=s then exit(true) else exit(false);
  end;

begin
  readln(n,m,k);
  for i:=1 to k do
    begin
      read(ch);
      hash[ch]:=1;
    end;
  for i:=1 to n do
    begin
      new(p);
      p^.dest:=0;
      p^.next:=nil;
      head[i]:=p;
      tail[i]:=p;
    end;
  for i:=1 to m do
    begin
      readln(x1,y1);
      push(x1,y1);
      push(y1,x1);
    end;
  readln(start,over);
  left:=1;
  right:=n+2;
  repeat
    mid:=(left+right) div 2;
    if check(mid) then right:=mid-1 else left:=mid+1;
  until left>right;
  if left>n then writeln(-1) else writeln(left);
end.