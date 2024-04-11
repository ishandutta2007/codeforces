program task;

{$APPTYPE CONSOLE}
{$O-}

uses
  Math,
  SysUtils;

var n,m,i,j,res,a,b,c,cur,a1,b1,c1:longint;
    cc:array[1..50,1..50]of longint;
    sums,sumc:array[0..50]of longint;

procedure sort(var x,y,z:longint);
var buf :longint;
begin
    if z < y then begin
        buf:=z;
        z:=y;
        y:=buf;
    end;
    if y<x then begin
        buf:=y;
        y:=x;
        x:=buf;
    end;
    if z<y then begin
        buf:=z;
        z:=y;
        y:=buf;
    end;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n,m);
    for i := 1 to n do begin
        for j := 1 to m do
            read(cc[i,j]);
        readln;
    end;
    readln(a,b,c);
    sort(a,b,c);
    res:=0;
    sums[0]:=0;
    for i := 1 to n do begin
        cur := 0;
        for j:=1 to m do
            cur := cur + cc[i,j];
        sums[i] := sums[i-1]+cur;
    end;
    sumc[0]:=0;
    for j := 1 to m do begin
        cur:=0;
        for i:= 1to n do
            cur :=cur+cc[i,j];
        sumc[j]:=sumc[j-1]+cur;
    end;
    for i:= 1to n-2 do
        for j := i+1 to n- 1 do begin
            a1:=sums[i];
            b1:=sums[j]-sums[i];
            c1:=sums[n]-sums[j];
            sort(a1,b1,c1);
            if (a=a1)and(b=b1)and(c=c1)then inc(res);
        end;
    for i:=1 to m- 2 do
        for j:= i+1 to m-1 do begin
            a1:=sumc[i];
            b1:=sumc[j]-sumc[i];
            c1:=sumc[m]-sumc[j];
            sort(a1,b1,c1);
            if(a=a1)and(b=b1)and(c=c1)then inc(res);
        end;
    writeln(res);
    halt(0);
end.