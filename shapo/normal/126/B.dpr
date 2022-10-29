program task;

{$APPTYPE CONSOLE}
//{$O-,R+,S+,Q+,I+}
{$O+,S-,Q-,R-,I-}

uses
  Math,
  SysUtils;

const naxm=2000000;

var s:string;
    res,p,i,len,nn,ff:longint;
    l:array[1..2*naxm]of longint;
    used:array[0..2*naxm]of boolean;

begin
    fillchar(used,sizeof(used),false);
    readln(s);
    res:=0;
    p:=0;
    l[1]:=0;
    nn:=length(s);
    for i:= 2 to nn do begin
        len:=l[i-1];
        while(len>0)and(s[len+1]<>s[i])do len:=l[len];
        if s[len+1]=s[i] then l[i]:=len+1 else l[i]:=0;
    end;
    ff:=l[nn];
    len:=ff;
    while len>0 do begin
        used[len]:=true;
        len:=l[len];
    end;
    for i:= 1 to nn-1 do
        if used[l[i]] and (res<l[i]) then begin
            res:=l[i];
            p:=i-res+1;
        end;
    if res=0 then begin
        writeln('Just a legend');
        halt(0);
    end;
    s:=copy(s,p,res);
    writeln(s);
    halt(0);
end.