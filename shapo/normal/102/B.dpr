{$APPTYPE CONSOLE}
uses Math,SysUtils;
var cur,i,p,res:longint;
    s:string;
begin
res:=1;
readln(s);
if length(s) = 1 then writeln(0) else begin
cur:=0;
for i:= 1 to length(s) do
    cur :=cur + ord(s[i])-ord('0');
while cur >= 10 do begin
	p:=0;
    while cur <>0  do begin
    	p:=p+cur mod 10;
        cur := cur div 10;
    end;
    inc(res);
    cur:=p;
end;
writeln(res);
end;
//readln;
end.