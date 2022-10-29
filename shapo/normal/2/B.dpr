program task;

{$APPTYPE CONSOLE}
{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

const maxn=1000;

var n,i,j,ii,ij:longint;
    ok:boolean;
    two,five:array[0..maxn,0..maxn]of longint;
    sm,r2,r5:array[1..maxn,1..maxn]of longint;

procedure init;
var i,j:longint;
begin
    for i:=0 to 1000 do
        for j :=0 to 1000 do begin
            two[i,j]:=100*1000*1000;
            five[i,j]:=two[i,j];
        end;
    fillchar(r2,sizeof(r2),0);
    fillchar(r5,sizeof(r5),0);
end;

function obr(x,y:longint):longint;
var res,m:longint;
begin
    m:=x;
    res:=0;
    while (m<>0)and(m mod y =0) do begin
        inc(res);
        m:=m div y;
    end;
    obr:=res;
end;

procedure make_path(a,b,c,d:longint);
var i:longint;
begin
    for i:= a to c-1 do
        write('D');
    for i:= b to d-1 do
        write('R');
end;

procedure rec(x,y,z:longint);
begin
    if (x<>1)or(y<>1) then begin
        if z=2 then begin
            if two[x,y]=two[x-1,y]+r2[x,y]
            then begin
                rec(x-1,y,z);
                write('D');
            end
            else begin
                rec(x,y-1,z);
                write('R');
            end;
        end
        else begin
            if five[x,y]=five[x-1,y]+r5[x,y]
            then begin
                rec(x-1,y,z);
                write('D');
            end
            else begin
                rec(x,y-1,z);
                write('R');
            end;
        end;
    end;
end;

begin
    init;
    readln(n);
    ok:=false;
    for i:=1 to n do begin
        for j:= 1 to n do begin
            read(sm[i,j]);
            r2[i,j]:=obr(sm[i,j],2);
            r5[i,j]:=obr(sm[i,j],5);
            ok:=ok or (sm[i,j] = 0);
        end;
        readln;
    end;
    two[1,1]:=r2[1,1];
    five[1,1]:=r5[1,1];
    for i:= 1 to n do
        for j:= 1 to n do
            if (i<>1)or(j<>1) then begin
                two[i,j]:=min(two[i,j-1],two[i-1,j])+r2[i,j];
                five[i,j]:=min(five[i-1,j],five[i,j-1])+r5[i,j];
            end;
    if ok then begin
        writeln(min(1,min(two[n,n],five[n,n])));
        if min(two[n,n],five[n,n])>1 then begin
            ii:=1;
            ij:=1;
            for i:=1 to n do
                for j:= 1 to n do
                    if sm[i,j]=0 then begin
                        ii:=i;
                        ij:=j;
                    end;
            make_path(1,1,ii,ij);
            make_path(ii,ij,n,n);
        end
        else
            if two[n,n]<five[n,n] then rec(n,n,2) else rec(n,n,5);
    end
    else begin
        writeln(min(two[n,n],five[n,n]));
        if two[n,n]<five[n,n] then rec(n,n,2) else rec(n,n,5);
    end;
    writeln;
    halt(0);
end.