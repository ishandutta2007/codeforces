{$APPTYPE CONSOLE}
uses Math,SysUtils;
var i,j,k:longint;
	n,m,res:longint;
    sm:array[1..100,1..100]of boolean;
    a:array[1..100]of longint;
begin
res:=4*1000*1000;
fillchar(sm,sizeof(sm),false);
readln(n,m);
for i:= 1 to n do
read(a[i]);
readln;
for k:= 1 to m do begin
	readln(i,j);
    sm[i,j]:=true;
    sm[j,i]:=true;
end;
for i := 1 to n-2 do
	for j := i+1 to n-1 do
    	for k := j+1 to n do
        	if sm[i,k] and sm[j,k]and sm[i,j] and(a[i]+a[j]+a[k]<res) then
            res:=a[i]+a[j]+a[k];
if res=4*1000*1000 then writeln(-1) else writeln(res);
//readln;
end.