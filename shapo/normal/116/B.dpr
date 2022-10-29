program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,m,i,j:longint;
    res:longint;
    a:array[0..11,0..11]of longint;
    c:char;

begin
    fillchar(a,sizeof(a),0);
    readln(n,m);
    for i:=1 to n do begin
        for j:=1  to m do begin
            read(c);
            if c='P' then a[i,j]:=1;
            if c='W'then a[i,j]:=2;
        end;
        readln;
    end;
    res:=0;
    for i:=1 to n do
        for j:=1 to m do
            if(a[i,j]=2)and((a[i-1,j]=1)or(a[i,j-1]=1)or(a[i+1,j]=1)or(a[i,j+1]=1))
            then inc(res);
    writeln(res);
    halt(0);
end.