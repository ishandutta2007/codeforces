program E;
var a1,a2,b1,b2,a,l:array[1..100000] of longint;
    f1,f2,r1,r2,n,i,t,k,m,p:longint;
begin
//  assign(input,'E.in');reset(input);
//  assign(output,'E.out');rewrite(output);
  readln(n,k);
  for i:=1 to n do read(a[i]);
  f1:=1;r1:=1;a1[1]:=a[1];b1[1]:=1;
  f2:=1;r2:=1;a2[1]:=a[1];b2[1]:=1;l[1]:=1;
  for i:=2 to n do
    begin
      l[i]:=l[i-1];t:=a[i];
      while (f1<=r1) and (a1[r1]<=t) do dec(r1);
      inc(r1);a1[r1]:=t;b1[r1]:=i;
      while (f2<=r2) and (a2[r2]>=t) do dec(r2);
      inc(r2);a2[r2]:=t;b2[r2]:=i;
      while a1[f1]-a2[f2]>k do
        begin
          inc(l[i]);
          if b1[f1]<l[i] then inc(f1);
          if b2[f2]<l[i] then inc(f2);
        end;
    end;
  m:=0;p:=1;
  for i:=1 to n do
    if i-l[i]+1>m then
      begin
        m:=i-l[i]+1;p:=1;
      end else
    if i-l[i]+1=m then inc(p);
  writeln(m,' ',p);
  for i:=1 to n do
    if i-l[i]+1=m then writeln(l[i],' ',i);
//  close(input);close(output);
end.