program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

const s:array[1..7]of char = ('R','O','Y','G','B','I','V');

var a,b,c,cur,i,a1,a2,a3,n:longint;
    res:array[1..100]of char;
    used:array[1..7]of boolean;

function ok:longint;
var i:longint;
begin
    i:=1;
    while used[i] do inc(i);
    ok:=i;
end;

begin
    readln(n);
    for i:= 1 to 7 do
        res[i]:=s[i];
    a:=5;
    b:=6;
    c:=7;
    a1:=1;
    a2:=2;
    a3:=3;
    for i:= 8 to n - 3 do begin
        fillchar(used,sizeof(used),false);
        used[a]:=true;used[b]:=true;used[c]:=true;
        cur:=ok;
        a:=b;
        b:=c;
        c:=cur;
        res[i]:=s[cur];
    end;
    if n-2 > 7 then begin
    i:=n-2;
    used[a]:=true;used[b]:=true;used[c]:=true;used[a1]:=true;
    cur:=ok;
    a:=b;
    b:=c;
    c:=cur;
    res[i]:=s[cur];
    end;
    if n-1 > 7 then begin
    i:=n-1;
    used[a]:=true;used[b]:=true;used[c]:=true;used[a1]:=true;used[a2]:=true;
    cur:=ok;
    a:=b;
    b:=c;
    c:=cur;
    res[i]:=s[cur];
    end;
    if n > 7 then begin
    i:=n;
    used[a]:=true;used[b]:=true;used[c]:=true;used[a1]:=true;used[a2]:=true;used[a3]:=true;
    cur:=ok;
    res[i]:=s[cur];
    end;
    for i:= 1 to n do
        write(res[i]);
    writeln;
    halt(0);
end.