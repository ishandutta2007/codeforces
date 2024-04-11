program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type typ=record
    x:longint;
    id:longint;
end;

var s:string;
    p,i,num,k,nc,l,j,ind:longint;
    n:array[1..26]of typ;
    color:array[1..1000]of longint;
    prime:array[1..1000]of boolean;
    mm:array[1..1000]of char;

procedure init;
var i,j:longint;
begin
    prime[1]:=false;
    prime[2]:=true;
    for i:= 3 to 1000 do begin
        j:=2;
        while (j*j<=i)and (i mod j <>0) do inc(j);
        prime[i]:=i mod j <> 0;
    end;
end;

begin
    fillchar(prime,sizeof(prime),false);
    fillchar(n,sizeof(n),0);
    fillchar(color,sizeof(color),0);
    num:=0;
    readln(s);
    init;
    k:=length(s);
    if k<=3 then begin
        writeln('YES');
        writeln(s);
        halt(0);
    end;
    nc:=0;
    inc(nc);
    color[1]:=1;
    for i:= 1 to k do begin
        if prime[i] then begin
            p:=i;
            while (p<=k) and (color[p]=0) do p:=p+i;
            if (p>k) then begin
                inc(nc);
                l:=nc;
            end
            else l:=color[p];
            p:=i;
            while (p<=k) do begin
                color[p]:=l;
                p:=p+i;
            end;
        end;
    end;
    for i:= 1 to k do
        if color[i]=color[2] then inc(num);
    for i:= 1 to k do
        inc(n[ord(s[i])-ord('a')+1].x);
    for i:=1to 26 do n[i].id:=26;
    ind:=1;
    for i:= 2 to 26 do
        if n[i].x>n[ind].x then ind:=i;
    if n[ind].x < num then begin
        writeln('NO');
        halt(0);
    end;
    writeln('YES');
    for i:=1 to k do
        if color[i]=color[2] then begin
            mm[i]:=chr(ord('a')-1+ind);
            dec(num);
            dec(n[ind].x);
        end
        else begin
            if n[ind].x=num then begin
            j:=1;
            while (n[j].x=0)or(j=ind) do inc(j);
            mm[i]:=chr(ord('a')-1+j);
            dec(n[j].x);
            end
            else begin
                mm[i]:=chr(ord('a')-1+ind);
                dec(n[ind].x);
            end;
        end;
    for i:=1 to k do
        write(mm[i]);
    writeln;
    halt(0);
end.