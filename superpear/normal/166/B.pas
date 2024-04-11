const eps=1e-12;

var x,y,x1,y1,x2,y2:array[0..240000] of longint;
    lm,rm,lk,rk,n,i,o1,o2,flag,xc,yc,m:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

function equal(a,b:extended):boolean;
  begin
    if abs(a-b)<=eps then exit(true) else exit(false);
  end;

function check(xc,yc:longint):boolean;
  var left,right,mid,c:longint;
      yu,yd:extended;
  begin
    if (xc<=lm) or (xc>=rm) then exit(false);
    left:=1;
    right:=o1;
    repeat
      mid:=(left+right) div 2;
      if x1[mid]<=xc then left:=mid+1 else right:=mid-1;
    until left>right;
    c:=right;
    yu:=y1[c]+(xc-x1[c])*((y1[c+1]-y1[c])/(x1[c+1]-x1[c]));
    if equal(yu,yc) then exit(false);
    left:=1;
    right:=o2;
    repeat
      mid:=(left+right) div 2;
      if x2[mid]<=xc then left:=mid+1 else right:=mid-1;
    until left>right;
    c:=right;
    yd:=y2[c]+(xc-x2[c])*((y2[c+1]-y2[c])/(x2[c+1]-x2[c]));
    if equal(yd,yc) then exit(false);
    if ((yu<yc) and (yc<yd)) or ((yu>yc) and (yc>yd)) then exit(true) else exit(false);
  end;

begin
  readln(n);
  for i:=1 to n do
    readln(x[i],y[i]);
  for i:=n+1 to n*2 do
    begin
      x[i]:=x[i-n];
      y[i]:=y[i-n];
    end;
  lm:=maxlongint;
  rm:=-maxlongint;
  lk:=0;
  rk:=0;
  for i:=1 to n do
    begin
      if x[i]<lm then
        begin
          lm:=x[i];
          lk:=i;
        end;
      if x[i]>rm then
        begin
          rm:=x[i];
          rk:=i;
        end;
    end;
  if lk>rk then rk:=rk+n;
  o1:=0;
  for i:=lk to rk do
    begin
      inc(o1);
      x1[o1]:=x[i];y1[o1]:=y[i];
    end;
  o2:=0;
  for i:=lk+n downto rk do
    begin
      inc(o2);
      x2[o2]:=x[i];y2[o2]:=y[i];
    end;
  //for i:=1 to o2 do writeln(x2[i],' ',y2[i]);

  readln(m);
  flag:=1;
  for i:=1 to m do
    begin
      readln(xc,yc);
      if not check(xc,yc) then
        begin
          flag:=0;
          break;
        end;
    end;
  if flag=0 then writeln('NO') else writeln('YES');
end.