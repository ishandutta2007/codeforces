program task;

{$APPTYPE CONSOLE}
{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

const p:array[1..4]of longint =(18279,703,27,1);

var n,i,num:longint;
    s:array[1..200] of string;
    res:array[1..200]of longint;
    sp:array[1..475254]of string;
    mt:array[1..475254]of longint;
    sm :array[1..200,0..6000] of longint;
    used:array[1..200]of boolean;
    ok:boolean;
    num1:longint;

procedure gen(x:longint; k :string);
var i:longint;
begin
    if x<> 0 then begin
        inc(num);
        sp[num]:=k;
    end;
    if (x <> 4) then
        for i:= 1 to 26 do
            gen(x+1,k+chr(ord('a')-1+i));
end;

function obr(s:string):longint;
var cur,i:longint;
begin
    cur:=0;
    i:=1;
    while (i<=length(s)) do begin
        cur := cur+p[i]*(ord(s[i])-ord('a'))+1;
        inc(i);
    end;
    obr:=cur;
end;

procedure make(a,b,c:longint;k:string);
begin
    if k<>'' then begin
        inc(sm[a][0]);
        sm[a][sm[a][0]]:=obr(k);
    end;
    if (c <> 4) and (b<=length(s[a])) then begin
        make(a,b+1,c+1,k+s[a][b]);
        make(a,b+1,c,k);
    end;
end;

function try_kuhn(u:longint):boolean;
var i,tt:longint;
    ok:boolean;
begin
    if used[u] then try_kuhn:=false else begin
        used[u]:=true;
        ok:=false;
        i := 1;
        while not ok and (i<=sm[u,0]) do begin
            tt:=sm[u,i];
            if (mt[tt]=-1) or try_kuhn(mt[tt]) then begin
                ok:=true;
                mt[tt]:=u;
            end;
            inc(i);
        end;
        try_kuhn:=ok;
    end;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n);
    num:=0;
    for i:=1 to n do begin
        readln(s[i]);
        sm[i][0]:=0;
    end;
    gen(0,'');
    //writeln(num);
    for i:= 1 to num do
        mt[i]:=-1;
    for i := 1 to n do
        make(i,1,0,'');
    for i:=1 to n do begin
        fillchar(used,sizeof(used),false);
        ok:=try_kuhn(i);
    end;
    num1:=0;
    for i:= 1 to num do
        if mt[i]<> -1 then begin
            inc(num1);
            res[mt[i]]:=i;
        end;
    if num1< n then writeln(-1)else begin
        for i:= 1 to n do
            writeln(sp[res[i]]);
    end;
    halt(0);
end.