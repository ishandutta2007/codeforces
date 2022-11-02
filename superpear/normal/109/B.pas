var b:array[0..10] of longint;
    f:array[0..10000] of longint;
    i,j,o,l1,r1,l2,r2,k,x1,y1:longint;
    all,ans:int64;

function jiao(x1,y1,x2,y2:longint):longint;
  begin
    if x2>y1 then exit(0);
    if x1>y2 then exit(0);
    if (x2>=x1) and (y1>=x2) and (y2>=y1) then exit(y1-x2+1);
    if (x1>=x2) and (y2>=x1) and (y1>=y2) then exit(y2-x1+1);
    if (x2<=x1) and (y2>=y1) then exit(y1-x1+1);
    if (x1<=x2) and (y1>=y2) then exit(y2-x2+1);
  end;

begin
  fillchar(f,sizeof(f),0);
  o:=0;
  for i:=1 to 9 do
    begin
      fillchar(b,sizeof(b),0);
      while b[0]=0 do
        begin
          inc(o);
          for j:=1 to i do
            if b[j]=0 then f[o]:=f[o]*10+4 else f[o]:=f[o]*10+7;
          j:=i;
          while b[j]=1 do
            begin
              b[j]:=0;
              dec(j);
            end;
          inc(b[j]);
        end;
    end;
  readln(l1,r1,l2,r2,k);
  all:=int64(r1-l1+1)*(r2-l2+1);
  ans:=0;
  f[0]:=-maxlongint div 2;
  f[o+1]:=maxlongint;
  for i:=1 to o-k+1 do
    begin
      x1:=i;
      y1:=i+k-1;
      ans:=ans+int64(jiao(f[x1-1]+1,f[x1],l1,r1))*jiao(f[y1],f[y1+1]-1,l2,r2)
              +int64(jiao(f[x1-1]+1,f[x1],l2,r2))*jiao(f[y1],f[y1+1]-1,l1,r1);
    end;
  if k=1 then
    for i:=1 to o do
      if (f[i]>=l1) and (f[i]<=r1) and (f[i]>=l2) and (f[i]<=r2) then
        dec(ans);
  writeln(ans/all:0:12);
end.