var x,y,a,b:array[0..1000000] of longint;
    m,n,e,c,k,i,max,ans,o1,o2:longint;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort1(l,r:longint);
  var i,j,c,d,e:longint;
  begin
    i:=l;
    j:=r;
    e:=random(r-l+1)+l;
    c:=x[e];
    d:=y[e];
    repeat
      while (y[i]<d) or ((y[i]=d) and (x[i]<c)) do inc(i);
      while (d<y[j]) or ((d=y[j]) and (c<x[j])) do dec(j);
      if i<=j then
        begin
          swap(x[i],x[j]);
          swap(y[i],y[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort1(l,j);
    if i<r then sort1(i,r);
  end;

procedure sort2(l,r:longint);
  var i,j,c,d,e:longint;
  begin
    i:=l;
    j:=r;
    e:=random(r-l+1)+l;
    c:=a[e];
    d:=b[e];
    repeat
      while (b[i]<d) or ((b[i]=d) and (a[i]<c)) do inc(i);
      while (d<b[j]) or ((d=b[j]) and (c<a[j])) do dec(j);
      if i<=j then
        begin
          swap(a[i],a[j]);
          swap(b[i],b[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort2(l,j);
    if i<r then sort2(i,r);
  end;

begin
  randomize;

  readln(n,m);
  for i:=1 to n do
    readln(x[i],y[i]);
  for i:=1 to m do
    readln(a[i],b[i]);
  sort1(1,n);
  sort2(1,m);
  e:=1;
  y[0]:=-maxlongint;
  max:=0;
  ans:=0;
  for i:=1 to n do
    if y[i]<>y[i-1] then
      begin
        k:=i;
        while y[k+1]=y[k] do inc(k);
        while b[e]<y[k] do inc(e);
        if b[e]=y[k] then
          begin
            c:=e;
            while b[c+1]=b[c] do inc(c);
            //writeln(i,' ',k,' ',e,' ',c,' ',max);
            ans:=ans+min(c-e+1,k-i+1);
            o1:=i;o2:=e;
            while (o1<=k) and (o2<=c) do
              begin
                if x[o1]=a[o2] then
                  begin
                    inc(max);
                    inc(o1);inc(o2);
                  end
                else
                  if x[o1]<a[o2] then inc(o1) else inc(o2);
              end;
            e:=c+1;
          end;
      end;
  //for i:=1 to n do writeln(x[i],' ',y[i]);
  //for i:=1 to m do writeln(a[i],' ',b[i]);
  writeln(ans,' ',max);
end.