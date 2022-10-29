var curx,cury,curz:longint;
i,x,y,z,n:longint;
begin
readln(n);
curx:=0;cury:=0;curz:=0;
for i:=1 to n do begin
    readln(x,y,z);
    curx:=curx+x;
    cury:=cury+y;
    curz:=curz+z;
end;
if (curx=0)and(cury=0)and(curz=0)then writeln('YES')else writeln('NO');
halt(0);
end.