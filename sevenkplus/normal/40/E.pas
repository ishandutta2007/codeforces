var x,y,d:array[1..1000] of longint;
    a:array[1..1000,1..1000] of longint;
    q:array[0..1000] of longint;
    n,m,t,k,i,j,p,s:longint;
    tt:int64;
    f:boolean;
begin
  readln(n,m,k);
  for i:=1 to k do readln(x[i],y[i],d[i]);
  readln(p);
  if odd(n) xor odd(m) then
    begin
      writeln(0);halt;
    end;
  if n<m then
    begin
      t:=m;m:=n;n:=t;
      for i:=1 to k do
        begin
          t:=x[i];x[i]:=y[i];y[i]:=t;
        end;
    end;
  fillchar(a,sizeof(a),0);
  for i:=1 to k do a[x[i],y[i]]:=d[i];
  for i:=1 to n do
    begin
      f:=true;
      for j:=1 to m do if a[i,j]<>0 then f:=false;
      if f then
        begin
          k:=i;break;
        end;
    end;
  for i:=1 to n do
    begin
      s:=1;
      for j:=1 to m do s:=s*a[i,j];
      if s=1 then begin writeln(0);halt;end;
    end;
  for j:=1 to m do
    begin
      s:=1;
      for i:=1 to n do s:=s*a[i,j];
      if s=1 then begin writeln(0);halt;end;
    end;
  q[0]:=1;
  for i:=1 to 1000 do q[i]:=q[i-1]*2 mod p;
  tt:=1;
  for i:=1 to n do
    if i<>k then
      begin
        s:=0;
        for j:=1 to m do if a[i,j]=0 then inc(s);
        if s<>0 then tt:=tt*q[s-1] mod p;
      end;
  writeln(tt);
end.