var a,b,x1,y1,x2,y2,c1,c2,ans:longint;
begin
  readln(a,b,x1,y1,x2,y2);
  c1:=x1+y1;
  c2:=x2+y2;
  if c1>0 then c1:=c1 div (a*2) else c1:=c1 div (a*2)-1;
  if c2>0 then c2:=c2 div (a*2) else c2:=c2 div (a*2)-1;
  ans:=abs(c1-c2);
  c1:=x1-y1;
  c2:=x2-y2;
  if c1>0 then c1:=c1 div (b*2) else c1:=c1 div (b*2)-1;
  if c2>0 then c2:=c2 div (b*2) else c2:=c2 div (b*2)-1;
  if abs(c1-c2)>ans then ans:=abs(c1-c2);
  writeln(ans);
end.