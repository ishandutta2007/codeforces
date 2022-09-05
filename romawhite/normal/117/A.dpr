var n,m,i,j,k,l,s,f,t:integer;
begin
read(n,m);
for i:=1 to n do
begin
read(s,f,t);
if s=f then writeln(t) else
begin
k:=t div (2*m-2);
t:=t mod (2*m-2);
if t>m-1+m-s then
if f<s then writeln((k+2)*(2*m-2)-f+1) else writeln((k+1)*(2*m-2)+f-1);
if t<=s-1 then
if f>=s then writeln(k*(2*m-2)+f-1) else writeln((k+1)*(2*m-2)-f+1);
if (t>s-1)and (t<=m-1+m-s) then
if f<=s  then writeln((k+1)*(2*m-2)-f+1) else writeln((k+1)*(2*m-2)+f-1);
end;
end;
end.