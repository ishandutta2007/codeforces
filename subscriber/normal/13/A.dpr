var
 g,b,l,ans,d,n,i:longint;

function gcd(a,b:longint):longint;
begin
 if b=0 then gcd:=a else gcd:=gcd(b,a mod b);
end;

begin
 readln(n);
 ans:=0;
 for i:=2 to n-1 do
 begin
  l:=n;
  d:=0;
  while l>0 do
  begin
   inc(d,l mod i);
   l:=l div i;
  end;
  inc(ans,d);
 end;
 b:=n-2;
 g:=gcd(ans,b);
 writeln(ans div g,'/',b div g);
end.