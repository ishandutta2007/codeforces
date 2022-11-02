var n,k,i,j,p,k1,k2,max,flag,e:longint;
    s:array[0..100] of ansistring;
    st,c1,c2:ansistring;
    a:array[0..100,0..100] of longint;
    b,ans:array[0..100] of longint;

begin
  readln(n,k);
  for i:=1 to n do
    readln(s[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if s[i]>s[j] then
        begin
          st:=s[i];
          s[i]:=s[j];
          s[j]:=st;
        end;
  fillchar(a,sizeof(a),0);
  for i:=1 to k do
    begin
      readln(st);
      p:=pos(' ',st);
      c1:=copy(st,1,p-1);
      c2:=copy(st,p+1,length(st)-p);
      for j:=1 to n do
        if s[j]=c1 then k1:=j;
      for j:=1 to n do
        if s[j]=c2 then k2:=j;
      a[k1,k2]:=1;a[k2,k1]:=1;
    end;
  fillchar(ans,sizeof(ans),0);
  max:=0;
  while b[0]=0 do
    begin
      j:=n;
      while b[j]=1 do
        begin
          b[j]:=0;
          dec(j);
        end;
      inc(b[j]);
      e:=0;
      for i:=1 to n do inc(e,b[i]);
      flag:=1;
      for i:=1 to n do
        for j:=1 to n do
          if (b[i]=1) and (b[j]=1) and (a[i,j]=1) then
            flag:=0;
      if flag=1 then
        if e>max then
          begin
            max:=e;
            ans:=b;
          end;
    end;
  writeln(max);
  for i:=1 to n do
    if ans[i]=1 then writeln(s[i]);
end.