var
 t,s,a,b:ansistring;
 p:array[1..400000]of longint;
 f,ff,t1,t2,i,x:longint;
 c:char;

begin
 readln(s);
 readln(a);
 readln(b);
 t:=a+'*'+s;
 p[1]:=0;
 f:=1000000;
 ff:=1000000;
 for i:=2 to length(t) do
 begin
  x:=p[i-1];
  while (x>0)and(t[x+1]<>t[i])do x:=p[x];
  if t[x+1]=t[i] then p[i]:=x+1 else p[i]:=0;
  if p[i]=length(a) then
  begin
   f:=i-length(a);
   break;
  end;
 end;
 t:=b+'*'+s;
 p[1]:=0;
 for i:=2 to length(t) do
 begin
  x:=p[i-1];
  while (x>0)and(t[x+1]<>t[i])do x:=p[x];
  if t[x+1]=t[i] then p[i]:=x+1 else p[i]:=0;
  if p[i]=length(b) then ff:=i-length(b);
 end;
 if f<ff-length(b)+1 then t1:=1;
 for i:=1 to length(s)shr 1 do
 begin
  c:=s[i];
  s[i]:=s[length(s)-i+1];
  s[length(s)-i+1]:=c;
 end;
 f:=1000000;
 ff:=1000000;
 t:=a+'*'+s;
 p[1]:=0;
 for i:=2 to length(t) do
 begin
  x:=p[i-1];
  while (x>0)and(t[x+1]<>t[i])do x:=p[x];
  if t[x+1]=t[i] then p[i]:=x+1 else p[i]:=0;
  if p[i]=length(a) then
  begin
   f:=i-length(a);
   break;
  end;
 end;
 t:=b+'*'+s;
 p[1]:=0;
 for i:=2 to length(t) do
 begin
  x:=p[i-1];
  while (x>0)and(t[x+1]<>t[i])do x:=p[x];
  if t[x+1]=t[i] then p[i]:=x+1 else p[i]:=0;
  if p[i]=length(b) then ff:=i-length(b);
 end;
 if f<ff-length(b)+1 then t2:=1;
 if t1+t2=2 then writeln('both')else
 if t1=1 then writeln('forward')else
 if t2=1 then writeln('backward')else writeln('fantasy');
end.