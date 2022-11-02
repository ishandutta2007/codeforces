const bigp=1000000007;

var f:array[0..3200,0..120,0..1] of longint;
    a,b:array[0..120] of longint;
    n,l,i,j,k,s,ans,last:longint;

begin
  readln(n,l);
  for i:=1 to n do
    readln(a[i],b[i]);
  fillchar(f,sizeof(f),0);
  f[0,0,0]:=1;
  for i:=0 to l do
    for j:=0 to n do
      for k:=0 to 1 do
        if f[i,j,k]>0 then
          for s:=1 to n do
            if s<>j then
              begin
                if j=0 then
                  begin
                    f[i+a[s],s,0]:=(f[i+a[s],s,0]+f[i,j,k]) mod bigp;
                    if a[s]<>b[s] then
                      f[i+b[s],s,1]:=(f[i+b[s],s,1]+f[i,j,k]) mod bigp;
                  end
                else
                  begin
                    if k=0 then last:=a[j] else last:=b[j];
                    if a[s]=last then
                      f[i+b[s],s,1]:=(f[i+b[s],s,1]+f[i,j,k]) mod bigp;
                    if (a[s]<>b[s]) and (b[s]=last) then
                      f[i+a[s],s,0]:=(f[i+a[s],s,0]+f[i,j,k]) mod bigp;
                  end;
              end;
  ans:=0;
  for i:=1 to n do
    for j:=0 to 1 do
      ans:=(ans+f[l,i,j]) mod bigp;
  writeln(ans);
end.