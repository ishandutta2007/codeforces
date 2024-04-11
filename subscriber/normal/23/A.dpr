var
 s:string;
 i,j,k,n,u,ans:longint;
begin
 readln(s);
 n:=length(s);
 ans:=0;
 for i:=1 to n do for j:=i+1 to n do
 begin
  u:=1;
  while true do
  begin
   if (j+u-1>n)or(s[i+u-1]<>s[j+u-1])then
   begin
    dec(u);
    break;
   end;
   inc(u);
  end;
  if u>ans then ans:=u;
 end;
 writeln(ans);
end.