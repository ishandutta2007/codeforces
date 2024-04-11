{$APPTYPE CONSOLE}
uses Math,SysUtils;
var n,k,i,a1,a2,b1,b2:longint;
begin
readln(n);
a1:=0;
a2:=0;
for i := 1 to n do begin
	read(k);
    if k mod 2=0 then begin
    	inc(a1);
    	if a1=1 then b1:=i; 
    end
	else begin
        inc(a2);
        if a2=1 then b2:=i;
    end;
end;
readln;
if a1=1 then writeln(b1) else writeln(b2);
//readln;
end.