program D_;
var x,y,l,a,p,d:array[1..5000] of longint;
    f:array[1..5000] of boolean;
    n,w,h,i,j,t,m,s,g:longint;
    b:boolean;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(n,w,h);
  for i:=1 to n do
    begin
      readln(x[i],y[i]);
      f[i]:=(x[i]>w) and (y[i]>h);l[i]:=i;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (x[i]>x[j]) or ((x[i]=x[j]) and (y[i]>y[j])) then
        begin
          t:=x[i];x[i]:=x[j];x[j]:=t;
          t:=y[i];y[i]:=y[j];y[j]:=t;
          t:=l[i];l[i]:=l[j];l[j]:=t;
          b:=f[i];f[i]:=f[j];f[j]:=b;
        end;
  for i:=1 to n do
    if not f[i] then
      begin
        a[i]:=0;p[i]:=0;
      end else
      begin
        a[i]:=1;p[i]:=0;
        if f[i] then
          for j:=1 to i-1 do
            if f[j] and ((x[j]<x[i]) and (y[j]<y[i])) and (a[j]>=a[i]) then
              begin
                p[i]:=j;a[i]:=a[j]+1;
              end;
      end;
  m:=-1;
  for i:=1 to n do
    if f[i] and (a[i]>m) then
      begin
        m:=a[i];s:=i;
      end;
  if m<=0 then writeln(0) else
    begin
      writeln(m);g:=0;
      while s<>0 do
        begin
          inc(g);d[g]:=l[s];s:=p[s];
        end;
      for i:=g downto 2 do write(d[i],' ');writeln(d[1]);
    end;
//  close(input);close(output);
end.