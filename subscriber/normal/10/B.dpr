var
 m,_,n,k,i,j,h,t,min,ax,ay,xx,yy:longint;
 f:array[1..100,1..100]of byte;
begin
 readln(n,k);
 fillchar(f,sizeof(f),0);
 xx:=k shr 1+1;
 yy:=xx;
 for _:=1 to n do
 begin
  read(m);
  min:=maxlongint;
  for i:=1 to k do for j:=1 to k-m+1 do
  begin
   t:=0;
   for h:=1 to m do if f[i,j+h-1]=1 then t:=1;
   if t=1 then continue;
   for h:=1 to m do inc(t,abs(i-xx)+abs(yy-(j+h-1)));
   if t<min then
   begin
    min:=t;
    ax:=i;
    ay:=j;
   end;
  end;
  if min=maxlongint then writeln(-1)else
  begin
   writeln(ax,' ',ay,' ',ay+m-1);
   for i:=ay to ay+m-1 do f[ax,i]:=1;
  end;
 end;
end.