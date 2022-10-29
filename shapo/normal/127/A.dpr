var k,n,i:longint;
res:extended;
a:array[1..1000,1..2]of longint;
begin
readln(n,k);
res:=0;
i:=1;
readln(a[i][1],a[i][2]);
for i:= 2 to n do begin
readln(a[i][1],a[i][2]);
res:=res+sqrt((a[i][1]-a[i-1][1])*(a[i][1]-a[i-1][1])
+(a[i][2]-a[i-1][2])*(a[i][2]-a[i-1][2]));
end;
writeln(res*k/50:0:10);
end.