var st1,st:ansistring;
    s1,s2:array[0..100000] of char;
    g:array[0..1000] of char;
    f,ans1,ans2:array[0..100000] of longint;
    m,n,i,ans:longint;

function doit(st:ansistring):boolean;
  var i,j,k:longint;
  begin
    k:=length(st);
    for i:=1 to k do
      g[i]:=st[i];
    j:=0;
    f[1]:=0;
    for i:=2 to k do
      begin
        while (j>0) and (g[j+1]<>g[i]) do j:=f[j];
        if g[j+1]=g[i] then inc(j);
        f[i]:=j;
      end;
    filldword(ans1,sizeof(ans1) div 4,maxlongint div 2);
    j:=0;
    for i:=1 to n do
      begin
        while (j>0) and (s1[i]<>g[j+1]) do j:=f[j];
        if g[j+1]=s1[i] then inc(j);
        if i<ans1[j] then ans1[j]:=i;
      end;
    for i:=1 to k do
      g[i]:=st[k+1-i];
    j:=0;
    f[1]:=0;
    for i:=2 to k do
      begin
        while (j>0) and (g[j+1]<>g[i]) do j:=f[j];
        if g[j+1]=g[i] then inc(j);
        f[i]:=j;
      end;
    filldword(ans2,sizeof(ans2) div 4,maxlongint div 2);
    j:=0;
    for i:=1 to n do
      begin
        while (j>0) and (s2[i]<>g[j+1]) do j:=f[j];
        if g[j+1]=s2[i] then inc(j);
        if i<ans2[j] then ans2[j]:=i;
      end;
    for i:=1 to k-1 do
      if ans1[i]+ans2[k-i]<=n then exit(true);
    exit(false);
  end;

begin
  readln(st1);
  n:=length(st1);
  for i:=1 to n do
    s1[i]:=st1[i];
  for i:=n downto 1 do
    s2[i]:=s1[n+1-i];
  readln(m);
  ans:=0;
  for i:=1 to m do
    begin
      readln(st);
      if doit(st) then inc(ans);
    end;
  writeln(ans);
end.