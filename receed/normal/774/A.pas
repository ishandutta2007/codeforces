var n,c1,c2,a,b,t,ans:int64;
i:integer;
s:string;

begin
a:=0;
b:=0;
readln(n,c1,c2);
readln(s);
for i:=0  to n do
 if s[i]='1' then a:=a+1
 else b:=b+1;
ans:=c1+c2*n*n;
for i:=1 to a do
 begin
 t:=c1*i+c2*((n div i - 1)*(n div i - 1)*(i-n mod i)+(n div i)*(n div i)*(n mod i));
 if t<ans then ans:=t;
 end;
write(ans);
end.