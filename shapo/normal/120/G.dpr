program task;

{$APPTYPE CONSOLE}
{$O+}

uses
  Math,
  SysUtils;

type slovo = record
    name : string;
    c:longint
end;

var n,t,i,m,beg,en,cur1,cur2,curt:longint;
    d:array[1..100,1..100]of longint;
    ob:array[1..100,0..100]of longint;
    a,b:array[1..100,1..2]of longint;
    q:array[1..1000000] of longint;
    sm:array[1..100]of slovo;

procedure obr(var x,y,z,dd:longint);
var p,fc:longint;
begin
    p:=q[x];
    fc:=max(1,sm[p].c -(a[y][z]+b[y][3-z]) - d[y][p]);
    if fc > dd then begin
        inc(d[y,p],dd);
        dd:=t;
        inc(y);
        if y>n then begin
            z:=3-z;
            y:=1;
        end;
        inc(en);
        q[en]:=p;
    end
    else begin
        dd:=dd-fc;
        inc(ob[y,0]);
        ob[y,ob[y,0]]:=p;
        if dd = 0 then begin
            dd:=t;
            inc(y);
            if y>n then begin
                z:=3-z;
                y:=1;
            end;
        end;
    end;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n,t);
    fillchar(d,sizeof(d),0);
    fillchar(ob,sizeof(ob),0);
    for i:= 1 to n do begin
        readln(a[i,1],b[i,1],a[i,2],b[i,2]);
    end;
    readln(m);
    beg:=1;
    en:=m;
    for i:= 1 to m do begin
        readln(sm[i].name);
        readln(sm[i].c);
        q[i]:=i;
    end;
    cur1:=1;
    cur2:=1;
    curt:=t;
    while beg<=en do begin
        obr(beg,cur1,cur2,curt);
        inc(beg);
    end;
    for i:= 1 to n do begin
        write(ob[i,0]);
        for curt:= 1 to ob[i,0] do
            write(' ', sm[ob[i,curt]].name);
        writeln;
    end;
end.