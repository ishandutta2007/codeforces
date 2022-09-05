program a1;
var s:string;
l,m,k,i,j:integer;
begin
readln(s);
l:=length(s);
for i:=1 to l do
if ord(s[i])<95 then s[i]:=chr(ord(s[i])+32);
for i:=1 to l do
if (s[i]<>'a') and (s[i]<>'o') and (s[i]<>'y') and (s[i]<>'e') and (s[i]<>'u') and (s[i]<>'i')
then write('.',s[i]); 
end.