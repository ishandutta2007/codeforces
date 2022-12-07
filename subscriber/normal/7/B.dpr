var
 o:char;
 b,x,l,t,m,_,i,j,n,k:longint;
 f:array[1..1000]of longint;
begin
 readln(t,m);
 fillchar(f,sizeof(f),0);
 b:=0;
 for _:=1 to t do
 begin
  read(o);
  if o='a' then
  begin
   readln(o,o,o,o,x);
   n:=0;
   for j:=m-x+1 downto 1 do
   begin
    l:=0;
    for k:=1 to x do if f[j+k-1]>0 then l:=1;
    if l=0 then n:=j;
   end;
   if n=0 then writeln('NULL')else
   begin
    inc(b);
    for j:=1 to x do f[n+j-1]:=b;
    writeln(b);
   end;
  end else if o='e' then
  begin
   readln(o,o,o,o,x);
   n:=0;
   for i:=1 to m do if f[i]=x then
   begin
    n:=1;
    f[i]:=0;
   end;
   if (n=0)or(x=0) then writeln('ILLEGAL_ERASE_ARGUMENT');
  end else
  begin
   readln;
   for i:=1 to m do if f[i]=0 then
   begin
    for j:=i+1 to m do if f[j]>0 then
    begin
     f[i]:=f[j];
     f[j]:=0;
     break;
    end;
   end;
  end;
 end;
end.