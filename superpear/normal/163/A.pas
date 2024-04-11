const bigp=1000000007;

var s,t:ansistring;
    s1,s2:array[0..10000] of char;
    m,n,i,j,ans:longint;
    f:array[0..5005,0..5005] of longint;

begin
  readln(s);
  readln(t);
  m:=length(s);
  n:=length(t);
  for i:=1 to m do s1[i]:=s[i];
  for i:=1 to n do s2[i]:=t[i];
  fillchar(f,sizeof(f),0);
  for i:=1 to m do
    for j:=1 to n do
      if s1[i]=s2[j] then f[i,j]:=1;
  for i:=1 to m do
    for j:=1 to n do
      begin
        //writeln(i,' ',j,' ',f[i,j]);
        f[i,j+1]:=(f[i,j+1]+f[i,j]) mod bigp;
        if s1[i+1]=s2[j+1] then
          f[i+1,j+1]:=(f[i+1,j+1]+f[i,j]) mod bigp;
      end;
  ans:=0;
  for i:=1 to m do
    ans:=(ans+f[i,n]) mod bigp;
  writeln(ans);
end.