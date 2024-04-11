const
 base=10000000000000007;
var
 s:ansistring;
 ans,i:longint;
 h1,h2,p:qword;
 d:array[0..5000000]of longint;
begin
// reset(input,'1.in');
 readln(s);
 h1:=0;
 h2:=0;
 d[0]:=0;
 ans:=0;
 p:=1;
 for i:=1 to length(s) do 
 begin
  h1:=h1*131+ord(s[i]);
//  if h1>=base then h1:=h1 mod base
  h2:=h2+ord(s[i])*p;
//  if h2>=base then h2:=h2 mod base;
  p:=p*131;
//  if p>=base then p:=p mod base;
  if h1=h2 then
  begin
   d[i]:=d[i shr 1]+1;
   inc(ans,d[i]);
  end;
 end;
 writeln(ans);
end.