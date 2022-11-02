const maxn=10000000;
var f:array[0..maxn] of shortint;
    i,j,n,s,c,e:longint;
begin
  fillchar(f,sizeof(f),0);
  f[1]:=1;
  for i:=2 to maxn do
    if f[i]=0 then
      for j:=i to (maxn div i) do
        f[i*j]:=1;
  readln(n);
  s:=0;
  for i:=1 to maxn do
    if f[i]=0 then
    begin
      c:=i;
      e:=0;
      while c>0 do
        begin
          e:=e*10+c mod 10;
          c:=c div 10;
        end;
      if (e<>i) and (f[e]=0) then inc(s);
      if s=n then
        begin
          writeln(i);
          halt;
        end;
    end;
end.