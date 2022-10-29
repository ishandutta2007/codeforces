uses Math,SysUtils;
var n,num,i,j,m,kk:longint;
    cur:array[1..1000]of string;
    sm,sm1,sm2:array[1..1000]of longint;
    used:array[1..1000]of boolean;
    res,curs:string;
function obr(i:longint; var k:longint):string;
var c:char;
    res:string;
begin
    res:='';
    read(c);
    while(c<>' ') do begin res:=res+c; read(c);end;
    readln(k);
    obr:=res;
end;

begin
    fillchar(used,sizeof(used),false);
    m:=0;
    res:='';
    readln(n);
    num:=0;
    for i := 1 to n do begin
        curs:=obr(i,kk);
        j:=1;
        while(j<=num)and(cur[j]<>curs)do inc(j);
        if j>num then begin
            inc(num);
            cur[num]:=curs;
            sm[num]:=kk;
        end
        else inc(sm[j],kk);
        sm1[i]:=j;
        sm2[i]:=kk;
    end;
    for i := 1 to num do
        m:=max(m,sm[i]);
    for i := 1 to num do begin
        used[i]:=sm[i]=m;
        sm[i]:=0;
    end;
    for i := 1 to n do begin
        inc(sm[sm1[i]],sm2[i]);
        if used[sm1[i]] and (sm[sm1[i]]>=m) and (res='') then
        res:=cur[sm1[i]];
    end;
    writeln(res);
    halt(0);
end.