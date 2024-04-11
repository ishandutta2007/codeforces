var cur:int64;
    x,m:int64;
    n,i:longint;
function xorr(u:int64):int64;
begin
    xorr:=0;
    if u mod 4 = 0 then xorr:=u;
    if u mod 4=3 then xorr:=0;
    if u mod 4=2 then xorr:=u+1;
    if u mod 4=1 then xorr:=1;
end;
begin
    cur:=0;
    readln(n);
    for i:= 1 to n do begin
        readln(x,m);
        cur:=cur xor xorr(x-1) xor xorr(x+m-1);
    end;
    if cur=0 then writeln('bolik') else writeln('tolik');
    halt(0);
end.