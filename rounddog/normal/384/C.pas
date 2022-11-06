
program cf225_3;

var
    i,j,k,l,m,n,p,q:longint;
    ans:int64;
    a,b,c:array[0..200200] of longint;

begin
  readln(n);
  p:=0;q:=0;
  for i:= 1 to n do
    begin
      read(a[i]);
      if a[i]=0 then inc(p) else inc(q);
    end;
  readln;
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  for i:= 2 to n do
    if a[i-1]=1 then b[i]:=b[i-1]+1 else b[i]:=b[i-1];
  for i:= n-1 downto 1 do
    if a[i+1]=0 then c[i]:=c[i+1]+1 else c[i]:=c[i+1];
  k:=1;l:=n;ans:=0;
  while k<=l do
    begin
      while (a[k]=0) and (k<=l) do inc(k);
      while (a[l]=1) and (l>=k) do dec(l);
      if k<l then ans:=ans+(c[k]-c[l]);
      inc(k);
      if l>k then ans:=ans+(b[l]-b[k]);
      dec(l);
    end;
  writeln(ans);
end.