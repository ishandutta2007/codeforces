var n,m,a:longint;
    ans,m2,n2:qword;
begin
readln(n,m,a);
if n mod a=0 then
  n2:=n div a else n2:=n div a+1;
if m mod a=0 then
  m2:=m div a else m2:=m div a+1;
ans:=n2*m2;
writeln(ans);
end.