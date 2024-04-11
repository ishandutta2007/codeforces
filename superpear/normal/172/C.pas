var a,b,t,x,ans:array[0..300000] of longint;
    m,n,i,time,o,e,j:longint;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

procedure sort(l,r:longint);
  var i,j,x,y:longint;
  begin
    i:=l;
    j:=r;
    x:=a[l+random(r-l+1)];
    repeat
      while a[i]<x do inc(i);
      while x<a[j] do dec(j);
      if i<=j then
        begin
          swap(a[i],a[j]);
          swap(b[i],b[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;


begin
  randomize;

  readln(n,m);
  for i:=1 to n do
    readln(t[i],x[i]);
  fillchar(ans,sizeof(ans),0);
  time:=0;
  for i:=1 to n do
    if (m=1) or (i mod m=1) then
      begin
        o:=0;
        e:=i;
        repeat
          inc(o);
          a[o]:=x[e];
          b[o]:=e;
          inc(e);
        until (e>n) or (m=1) or (e mod m=1);
        dec(e);
        if t[e]>time then time:=t[e];
        sort(1,o);
        a[0]:=0;
        for j:=1 to o do
          if a[j]<>a[j-1] then
            begin
              time:=time+a[j]-a[j-1];
              e:=j;
              ans[b[j]]:=time;
              while (e<o) and (a[e+1]=a[e]) do
                begin
                  inc(e);
                  ans[b[e]]:=time;
                end;
              e:=e-j+1;
              time:=time+1+e div 2;
            end;
        time:=time+a[o];
      end;
  for i:=1 to n-1 do write(ans[i],' ');writeln(ans[n]);
end.