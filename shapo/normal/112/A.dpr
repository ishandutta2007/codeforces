var s1,s2:string;
    i:longint;
function obr(c:char):char;
begin
if ord(c)<ord('a')then obr:= chr(ord(c)+32) else
obr:=c;
end;
begin
readln(s1);
readln(s2);
i:=1;
while(i<=length(s1))and(obr(s1[i])=obr(s2[i]))do inc(i);
if i>length(s1) then writeln(0) else begin
if obr(s1[i])<obr(s2[i]) then writeln(-1) else writeln(1);
end;
halt(0);
end.