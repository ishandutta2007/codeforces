program E;
var h,h1,l,r,c:array[0..1000010] of longint;
    i,n,m,p:longint;
    s:int64;
begin
//  assign(input,'E.in');reset(input);
//  assign(output,'E.out');rewrite(output);
  readln(n);m:=0;p:=0;
  for i:=1 to n do
    begin
      read(h1[i]);
      if h1[i]>m then
        begin
          m:=h1[i];p:=i;
        end;
    end;
  for i:=p to n do h[i-p+1]:=h1[i];
  for i:=1 to p-1 do h[i+n-p+1]:=h1[i];h[n+1]:=m;
  fillchar(c,sizeof(c),0);
  fillchar(r,sizeof(r),0);
  fillchar(l,sizeof(l),0);
  for i:=n downto 1 do
    begin
      r[i]:=i+1;
      while (r[i]<=n) and (h[i]>h[r[i]]) do r[i]:=r[r[i]];
      if (r[i]<=n) and (h[i]=h[r[i]]) then
        begin
          c[i]:=c[r[i]]+1;r[i]:=r[r[i]];
        end;
    end;
  for i:=1 to n do
    begin
      l[i]:=i-1;
      while (l[i]>0) and (h[i]>=h[l[i]]) do l[i]:=l[l[i]];
//      if (l[i]>0) and (h[i]=h[l[i]]) then l[i]:=l[l[i]];
    end;
//  write('h');for i:=1 to n do write(' ',h[i]);writeln;
//  write('l');for i:=1 to n do write(' ',l[i]);writeln;
//  write('r');for i:=1 to n do write(' ',r[i]);writeln;
//  write('c');for i:=1 to n do write(' ',c[i]);writeln;
  s:=0;
  for i:=1 to n do
    begin
      inc(s,c[i]);
      if h[i]<m then
        if (l[i]=1) and (r[i]=n+1)then inc(s) else inc(s,2);
    end;
  writeln(s);
//  close(input);close(output);
end.