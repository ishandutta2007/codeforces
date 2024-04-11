const maxn=100000;

type two=record
           x,y:extended;
         end;

var a,c,d:array[0..maxn] of two;
    b:array[0..maxn] of longint;
    i,j,sum,o1,o2,flag:longint;

function equal(a,b:extended):boolean;
  begin
    if abs(a-b)<=1e-10 then exit(true) else exit(false);
  end;

function dis(a,b:two):extended;
  begin
    exit(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
  end;

function dis2(a,b:two):extended;
  begin
    exit(sqr(a.x-b.x)+sqr(a.y-b.y));
  end;

function rec(a,b,c:two):boolean;
  begin
    if equal(dis2(a,b)+dis2(b,c),dis2(a,c)) then exit(true) else exit(false);
  end;

function area(a,b,c,d:two):extended;
  var s:extended;
  begin
    s:=b.x*a.y-a.x*b.y+c.x*b.y-b.x*c.y+d.x*c.y-c.x*d.y+a.x*d.y-d.x*a.y;
    exit(s);
  end;

function cq(a1,b1,c1,d1:longint):boolean;
  begin
    if equal(area(c[a1],c[b1],c[c1],c[d1]),0) then exit(false);
    if  equal(dis2(c[a1],c[b1]),dis2(c[b1],c[c1]))
    and equal(dis2(c[b1],c[c1]),dis2(c[c1],c[d1]))
    and equal(dis2(c[c1],c[d1]),dis2(c[d1],c[a1])) then
      if rec(c[a1],c[b1],c[c1]) and rec(c[b1],c[c1],c[d1]) and rec(c[c1],c[d1],c[a1]) then
        exit(true);
    exit(false);
  end;

function dq(a1,b1,c1,d1:longint):boolean;
  begin
    if equal(area(d[a1],d[b1],d[c1],d[d1]),0) then exit(false);
    if rec(d[a1],d[b1],d[c1]) and rec(d[b1],d[c1],d[d1]) and rec(d[c1],d[d1],d[a1]) then
      exit(true);
    exit(false);
  end;

begin
  for i:=1 to 8 do
    readln(a[i].x,a[i].y);
  flag:=1;
  fillchar(b,sizeof(b),0);
  while b[0]=0 do
    begin
      j:=8;
      while b[j]=1 do
        begin
          b[j]:=0;
          dec(j);
        end;
      inc(b[j]);
      sum:=0;
      for i:=1 to 8 do inc(sum,b[i]);
      if sum=4 then
        begin
          o1:=0;
          o2:=0;
          for i:=1 to 8 do
            if b[i]=0 then
              begin
                inc(o1);
                c[o1]:=a[i];
              end
            else
              begin
                inc(o2);
                d[o2]:=a[i];
              end;
          if cq(1,2,3,4) or cq(1,2,4,3) or cq(1,3,2,4) or cq(1,3,4,2) or cq(1,4,2,3) or cq(1,4,3,2) then
            if dq(1,2,3,4) or dq(1,2,4,3) or dq(1,3,2,4) or dq(1,3,4,2) or dq(1,4,2,3) or dq(1,4,3,2) then
              begin
                writeln('YES');
                flag:=0;
                o1:=0;
                for i:=1 to 8 do
                  if b[i]=0 then
                    begin
                      inc(o1);
                      if o1<>1 then write(' ');
                      write(i);
                    end;
                writeln;
                o1:=0;
                for i:=1 to 8 do
                  if b[i]=1 then
                    begin
                      inc(o1);
                      if o1<>1 then write(' ');
                      write(i);
                    end;
                writeln;
                break;
              end;
        end;
      if flag=0 then break;
    end;
  if flag=1 then writeln('NO');
end.