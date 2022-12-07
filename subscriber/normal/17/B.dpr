var
 m,n,a,b,c,i,l,ans:longint;
 t:array[1..1000]of longint;
begin
 readln(n);
 for i:=1 to n do read(a);
 readln(m);
 fillchar(t,sizeof(t),127);
 for i:=1 to m do
 begin
  readln(a,b,c);
  if c<t[b] then t[b]:=c;
 end;
 ans:=0;
 l:=0;
 for i:=1 to n do if t[i]<1000000000 then inc(ans,t[i])else
 begin
  if l=1 then
  begin
   writeln(-1);
   halt;
  end else l:=1;
 end;
 writeln(ans);
end.