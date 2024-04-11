program D;
var a,b,f,q:array[1..500] of longint;
    p:array[1..500,1..500] of longint;
    n,m,i,j,k,s:longint;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(m);
  for i:=1 to m do read(b[i]);
  fillchar(f,sizeof(f),0);
  fillchar(p,sizeof(p),0);
  for i:=1 to n do
    begin
      k:=0;
      if i<>1 then for j:=1 to m do p[i,j]:=p[i-1,j];
      for j:=1 to m do
        begin
          if (b[j]<a[i]) and (f[j]>f[k]) then k:=j;
          if (b[j]=a[i]) and (f[k]+1>f[j]) then
            begin
              f[j]:=f[k]+1;
              p[i,j]:=i*(m+1)+k;
            end;
        end;
    end;
  s:=0;
  for i:=1 to m do if f[i]>f[s] then s:=i;
  if s=0 then
    begin
      writeln(0);writeln;
    end else
    begin
      i:=n*m+n+s;
      for j:=f[s] downto 1 do
        begin
          q[j]:=b[i mod (m+1)];
          i:=p[i div (m+1),i mod (m+1)];
        end;
      writeln(f[s]);
      for i:=1 to f[s]-1 do write(q[i],' ');writeln(q[f[s]]);
    end;
//  close(input);close(output);
end.