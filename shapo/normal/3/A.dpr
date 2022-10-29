program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

const dx:array[1..8]of longint = (1, 1, 1, 0, -1, -1, -1,0);
      dy:array[1..8]of longint = (1, 0, -1, -1, -1, 0, 1, 1);
      pp:array[1..8]of string = ('RU','R','RD','D','LD','L','LU','U');

var sx,sy,tx,ty:longint;
    res,beg,en:longint;
    mn:array[1..8,1..8]of longint;
    q:array[1..64,1..2]of longint;
    used:array[1..8,1..8]of boolean;

procedure obr(var a,b:longint);
var c:char;
begin
    read(c);
    a:=ord(c)-ord('a')+1;
    readln(c);
    b:=ord(c)-ord('0');
end;

procedure BFS(x,y:longint);
var cx,cy,i:longint;
begin
    for i:= 1 to 8 do begin
        cx:=x+dx[i];
        cy:=y+dy[i];
        if (cx>=1)and(cx<=8)and(cy>=1)and(cy<=8)and not used[cx,cy] then begin
            used[cx,cy]:=true;
            inc(en);
            q[en][1]:=cx;
            q[en][2]:=cy;
            mn[cx,cy]:=mn[x,y]+1;
        end;
    end;
end;

procedure ans(a,b:longint);
var i,ind,da,db:longint;
begin
    if (a<>sx)or(b<>sy)then begin
        i:=1;
        ind:=1;
        while ind<>0 do begin
            da:=a-dx[i];
            db:=b-dy[i];
            if (da>=1)and(db>=1)and(da<=8)and(db<=8)
            and (mn[a,b]=mn[da,db]+1) then begin
                ind:=0;
                ans(da,db);
                writeln(pp[i]);
            end;
            inc(i);
        end;
    end;
end;

begin
    fillchar(used,sizeof(used),false);
    obr(sx,sy);
    obr(tx,ty);
    used[sx,sy]:=true;
    mn[sx,sy]:=0;
    beg:=1;
    en:=1;
    q[1][1]:=sx;
    q[1][2]:=sy;
    while (beg<=en) do begin
        BFS(q[beg][1],q[beg][2]);
        inc(beg);
    end;
    res:=mn[tx,ty];
    writeln(res);
    ans(tx,ty);
    halt(0);
end.