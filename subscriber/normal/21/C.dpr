var
 a,f,q:array[0..600000]of int64;
 i,n:longint;
 s,ans:int64;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 s:=0;
 for i:=1 to n do inc(s,a[i]);
 f[0]:=0;
 q[0]:=0;
 for i:=1 to n do
 begin
  f[i]:=f[i-1]+a[i];
  if f[i]+f[i]+f[i]=s then q[i]:=q[i-1]+1 else q[i]:=q[i-1];
 end;
 fillchar(f,sizeof(f),0);
 for i:=n downto 2 do
 begin
  f[i]:=f[i+1]+a[i];
  if f[i]+f[i]+f[i]=s then inc(ans,q[i-2]);
 end;
 writeln(ans);
end.