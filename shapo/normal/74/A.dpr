uses Math,SysUtils;
var n,i,ind:longint;
    cur:array[1..50]of string;
    res:array[1..50]of longint;
    
procedure obr(u:longint);
var curs:string;
    a,b,c,d,e,p,m:longint;
    cc:char;
begin
    curs:='';
    read(cc);
    while (cc<>' ') do begin
        curs:=curs+cc;
        read(cc);
    end;
    cur[u]:=curs;
    readln(p,m,a,b,c,d,e);
    res[u]:=a+b+c+d+e+(p*100)-m*50;
    if res[u]>res[ind] then ind:=u;
end;

begin
    ind:=1;
    readln(n);
    for i:= 1 to n do obr(i);
    writeln(cur[ind]);
end.