var a,s,l:array[0..100100] of int64;
    n,i,xt,yt,xx,yy:longint;
    t:int64;
begin
  readln(n);s[0]:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      s[i]:=s[i-1]+a[i];
    end;
  if s[n] mod 3<>0 then
    begin
      writeln(0);
      halt;
    end;
  t:=0;
  for i:=1 to n do
    if s[i]=s[n] div 3 then l[i]:=l[i-1]+1 else l[i]:=l[i-1];
  for i:=2 to n do
    if s[n]-s[i-1]=s[n] div 3 then inc(t,l[i-2]);
  writeln(t);
end.