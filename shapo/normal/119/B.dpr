program task;

{$APPTYPE CONSOLE}
{$R+,S+,Q+,I+,O+}

uses
  Math,
  SysUtils;

var a:array[1..100]of extended;
    add:array[1..100]of extended;
    used:array[1..100]of boolean;
    mn,mx:extended;
    sp:array[1..100]of extended;
    n,k,i,q,num,n1:longint;
    p1:extended;

procedure obr(x:longint);
var i,p:longint;
    cur:real;
begin
    cur:=0;
    for i:= 1 to n div k do begin
        read(p);
        used[p]:=true;
        cur:=cur+a[p];
    end;
    cur:=cur/(n div k);
    inc(num);
    add[num]:=cur;
    mn:=min(cur,mn);
    mx:=max(cur,mx);
end;

procedure bubble;
var i, j:longint;
    bbb:real;
begin
    for i:=2 to n1 do
        for j:= n1 downto i do
            if sp[j -1]>sp[j] then begin
                bbb:=sp[j];
                sp[j]:=sp[j-1];
                sp[j-1]:=bbb;
            end;
end;

begin
    fillchar(used,sizeof(used),false);
    readln(n,k);
    num:=0;
    for i:=1to n do
        read(a[i]);
    readln;
    mn:=100500;
    mx:=-10;
    readln(q);
    n1:=0;
    for i:=1 to q do
        obr(i);
    for i:= 1to n do
        if not used[i] then begin
            inc(n1);
            sp[n1]:=a[i];
        end;
    bubble;
    if (n1 >= n div k) and (n1 > n- k * (n div k)) then begin
        p1:=0;
        for i:=1to n div k do
            p1 :=p1+sp[i];
        p1:=p1/(n div k);
        mn:=min(mn,p1);
        mx:=max(mx,p1);
        p1:=0;
        for i:=(n1 - n div k+ 1)to n1 do
            p1 :=p1+sp[i];
        p1:=p1/(n div k);
        mn:=min(mn,p1);
        mx:=max(mx,p1);
    end;
    writeln(mn:0:10,' ',mx:0:10);
    halt(0);
end.