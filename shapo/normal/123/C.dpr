program task;

{$APPTYPE CONSOLE}
{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

var n,m,i,j,len,ind,cur:longint;
    k:int64;
    sm:array[0..200,-1..100]of int64;
    ok:array[1..200]of longint;
    res:array[1..100,1..100]of longint;
    sp:array[1..200]of longint;

procedure try_make(x:longint);
var i,j:longint;
begin
    ok[x]:=1;
    fillchar(sm,sizeof(sm),0);
    sm[0,0]:=1;
    for i:= 1 to len do
        for j:= 0 to (len div 2) do
            if ok[i]=0 then sm[i,j]:=min(k,sm[i-1,j+1]+sm[i-1,j-1]) else
                if ok[i]=1 then sm[i,j]:=sm[i-1,j-1] else sm[i,j]:=sm[i-1,j+1];
    if sm[len,0]< k then begin
        ok[x]:=-1;
        k:=k - sm[len,0];
    end;
end;

procedure recover;
var i,j:longint;
begin
    for i:= 1 to n do
        for j:= 1 to m do
            res[i,j]:=ok[i+j-1];
end;

begin
    //assign(input,'input.txt');
    fillchar(ok,sizeof(ok),0);
    fillchar(res,sizeof(res),0);
    readln(n,m,k);
    len:=n+m-1;
    for i:= 1 to len do
        sp[i]:=n*m+1;
    for i:= 1 to n do begin
        for j:= 1 to m do begin
            read(cur);
            sp[i+j-1]:=min(sp[i+j-1],cur);
        end;
        readln;
    end;
    for i:= 1 to len do begin
        ind:=1;
        for j:= 1 to len do
            if sp[ind]>sp[j] then ind:=j;
        sp[ind]:=n*m+1;
        try_make(ind);
    end;
    recover;
    for i:=1 to n do begin
        for j:= 1 to m do
            if res[i,j]=1 then write('(') else write(')');
        writeln;
    end;
    halt(0);
end.