var s:string;
    e,n,i,j,k,v,q,c1,max:longint;
    f:array[0..120,0..120,-120..120,0..1] of longint;

begin
  readln(s);
  readln(e);
  n:=length(s);
  fillchar(f,sizeof(f),0);
  f[0,0,0,0]:=1;
  for i:=0 to n-1 do
    for j:=0 to e do
      for k:=-100 to 100 do
        for v:=0 to 1 do
          if f[i,j,k,v]=1 then
            begin
              if s[i+1]='F' then c1:=1 else c1:=0;
              f[i+1,j+c1,k,1-v]:=1;
              if s[i+1]='T' then c1:=1 else c1:=0;
              if v=0 then q:=k+1 else q:=k-1;
              f[i+1,j+c1,q,v]:=1;
            end;
  max:=0;
  for j:=0 to e do
    if j mod 2=e mod 2 then
      for k:=-100 to 100 do
        for v:=0 to 1 do
          if f[n,j,k,v]=1 then
            if abs(k)>max then max:=abs(k);
  writeln(max);
end.