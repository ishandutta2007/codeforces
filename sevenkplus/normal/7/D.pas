program D;
var f:array[0..5000100] of longint;
    p:array[1..10001000] of longint;
    h:array[1..10000100] of boolean;
    s:array[1..10000100] of char;
    n,i,j,n1:longint;
    t:int64;
begin
//  assign(input,'D.in');reset(input);
//  assign(output,'D.out');rewrite(output);
  n:=0;
  while not eoln do
    begin
      inc(n);read(s[n]);
    end;
  n1:=n+1;s[n1]:='.';
  for i:=n downto 1 do
    begin
      inc(n1);s[n1]:=s[i];
    end;
  p[1]:=0;j:=0;n1:=n shl 1+1;
  for i:=2 to n1 do
    begin
      while (j>0) and (s[j+1]<>s[i]) do j:=p[j];
      if s[j+1]=s[i] then j:=j+1;p[i]:=j;
    end;
  fillchar(h,sizeof(h),false);
  i:=n1;
  while i<>0 do
    begin
      h[i]:=true;i:=p[i];
    end;
  f[0]:=0;
  for i:=1 to n do
    if h[i] then f[i]:=f[i shr 1]+1 else f[i]:=0;
  t:=0;
  for i:=1 to n do inc(t,f[i]);
  writeln(t);
//  close(input);close(output);
end.