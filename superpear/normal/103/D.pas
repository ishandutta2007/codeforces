var n,i,j,k,u,v:longint;
    a,p,t,e:array[0..300000] of longint;
    ans,f:array[0..300000] of int64;

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
    x:=p[l+random(r-l+1)];
    repeat
      while p[i]<x do inc(i);
      while x<p[j] do dec(j);
      if i<=j then
        begin
          swap(p[i],p[j]);
          swap(t[i],t[j]);
          swap(e[i],e[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  randomize;

  readln(n);
  for i:=1 to n do read(a[i]);
  readln(k);
  for i:=1 to k do
    begin
      readln(t[i],p[i]);
      e[i]:=i;
    end;
  sort(1,k);
  p[0]:=-maxlongint;
  fillchar(ans,sizeof(ans),0);
  for i:=1 to k do
    if p[i]<>p[i-1] then
      begin
        j:=i;
        while p[j+1]=p[j] do inc(j);
        if p[i]<=500 then
          begin
            for v:=n downto 1 do
              if v+p[i]>n then f[v]:=a[v] else f[v]:=f[v+p[i]]+a[v];
            for v:=i to j do
              ans[e[v]]:=f[t[v]];
          end
        else
          begin
            for v:=i to j do
              begin
                u:=t[v];
                while u<=n do
                  begin
                    inc(ans[e[v]],a[u]);
                    u:=u+p[v];
                  end;
              end;
          end;
      end;
  for i:=1 to k do
    writeln(ans[i]);
end.