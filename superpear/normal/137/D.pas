var st:ansistring;
    n,i,j,k,e,min,mink,u,v,p,o:longint;
    s:array[0..600] of char;
    a,f,g:array[0..600,0..600] of longint;
    x1,y1:array[0..600] of longint;

procedure doit(x,y:longint);
  var i,mid:longint;
  begin
    mid:=(x+y) div 2;
    for i:=x to y do
      if i<=mid then write(s[i]) else write(s[x+y-i]);
  end;

begin
  readln(st);
  readln(k);
  n:=length(st);
  for i:=1 to n do s[i]:=st[i];
  for i:=n downto 1 do
    for j:=i to n do
      if i>=j then a[i,j]:=0 else
        if s[i]=s[j] then a[i,j]:=a[i+1,j-1] else
          a[i,j]:=a[i+1,j-1]+1;
  filldword(f,sizeof(f) div 4,maxlongint);
  fillchar(g,sizeof(g),0);
  f[0,0]:=0;
  for i:=1 to n do
    for j:=1 to k do
      for e:=0 to i-1 do
        if (f[e,j-1]<>maxlongint) and (f[e,j-1]+a[e+1,i]<f[i,j]) then
          begin
            f[i,j]:=f[e,j-1]+a[e+1,i];
            g[i,j]:=e;
          end;
  min:=maxlongint;
  mink:=0;
  for i:=1 to k do
    if f[n,i]<min then
      begin
        min:=f[n,i];
        mink:=i;
      end;
  writeln(min);
  u:=n;
  v:=mink;
  o:=0;
  while u>0 do
    begin
      p:=g[u,v];
      inc(o);
      x1[o]:=p+1;y1[o]:=u;
      u:=g[u,v];
      dec(v);
    end;
  for i:=o downto 1 do
    begin
      doit(x1[i],y1[i]);
      if i<>1 then write('+') else writeln;
    end;
end.