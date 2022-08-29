var
 n,i,j,v,mo,ans:longint;
 f,g:array[-10005..10005]of longint;
begin
 readln(n);
 mo:=1000000007;ans:=0;
 for i:=1 to n do
 begin
   for j:=-10000 to 10000 do g[j]:=0;
   read(v);
   g[v]:=1;
   g[-v]:=1;
   for j:=-10000 to 10000 do
   if(f[j]<>0)then
   begin
    inc(g[j+v],f[j]);g[j+v]:=g[j+v] mod mo;
    inc(g[j-v],f[j]);g[j-v]:=g[j-v] mod mo;
   end;
   for j:=-10000 to 10000 do
   f[j]:=g[j];
   inc(ans,g[0]);
   ans:=ans mod mo;
 end;
 writeln(ans);
end.